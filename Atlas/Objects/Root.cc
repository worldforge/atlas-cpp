// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Stefanus Du Toit and Alistair Riddoch

#include <Atlas/Message/Encoder.h>
#include <Atlas/Objects/Root.h>

using Atlas::Message::Object;

namespace Atlas { namespace Objects {

Root::Root() : attr_id("root"), attr_objtype("meta")
{
    // SetId("root");
    // SetObjtype("meta");
}

Root::Root(const std::string& id) : attr_parents(1, std::string("root")),
                                    attr_id(id),
                                    attr_objtype("instance")
{
    // SetParents(Object::ListType(1,std::string("root")));
    // SetId(id);
    // SetObjtype("instance");
}

Root::Root(const std::string& id, const std::string & parent)
                                : attr_parents(1,parent), attr_id(id)
{
    // SetId(id);
    // SetParents(Object::ListType(1,parent));
}

Root::~Root()
{
}

Root Root::Instantiate()
{
    Root root("");
    return root;
}

bool Root::HasAttr(const std::string& name) const
{
    if (name == "parents") return true;
    if (name == "id") return true;
    if (name == "objtype") return true;
    if (name == "name") return true;
    return (attributes.find(name) != attributes.end());
}

Object Root::GetAttr(const std::string& name) const
    throw (NoSuchAttrException) 
{
    if (name == "parents") return attr_parents;
    if (name == "id") return attr_id;
    if (name == "objtype") return attr_objtype;
    if (name == "name") return attr_name;
    Object::MapType::const_iterator I = attributes.find(name);
    if (I == attributes.end())
        throw NoSuchAttrException(name);
    return ((*I).second);
}

void Root::SetAttr(const std::string& name, const Object& attr)
{
    if (name == "parents") { SetParents(attr.AsList()); return; }
    if (name == "id") { SetId(attr.AsString()); return; }
    if (name == "objtype") { SetObjtype(attr.AsString()); return; }
    if (name == "name") { SetName(attr.AsString()); return; }
    attributes[name] = attr;
}

void Root::RemoveAttr(const std::string& name)
{
    if (name == "parents") return;
    if (name == "id") return;
    if (name == "objtype") return;
    if (name == "name") return;
    attributes.erase(name);
}

Object Root::AsObject() const
{
    Object::MapType allattrs = attributes;
    allattrs["parents"] = Object(attr_parents);
    allattrs["id"] = Object(attr_id);
    allattrs["objtype"] = Object(attr_objtype);
    allattrs["name"] = Object(attr_name);
    return Object(allattrs);
}

Object::MapType Root::AsMap() const
{
    Object::MapType allattrs = attributes;
    allattrs["parents"] = Object(attr_parents);
    allattrs["id"] = Object(attr_id);
    allattrs["objtype"] = Object(attr_objtype);
    allattrs["name"] = Object(attr_name);
    return allattrs;
}

void Root::SendContents(Bridge* b) const
{
    SendParents(b);
    SendId(b);
    SendObjtype(b);
    SendName(b);

    Message::Encoder e(b);
    typedef std::map<std::string, Object>::const_iterator Iter;
    for (Iter I = attributes.begin(); I != attributes.end(); I++)
        e.MapItem((*I).first, (*I).second);
}

} } // namespace Atlas::Objects
