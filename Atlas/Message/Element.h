// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit

#ifndef ATLAS_MESSAGE_OBJECT_H
#define ATLAS_MESSAGE_OBJECT_H

#include <string>
#include <map>
#include <list>

namespace Atlas { namespace Message {

/// An exception class issued when the wrong type is requested in As().
class WrongTypeException { };

/** Multi-type container
 *
 * FIXME: Document this
 *
 * @author Stefanus Du Toit <sdt@gmx.net>
 */
class Object
{
public:
    typedef int IntType;
    typedef double FloatType;
    typedef std::string StringType;
    typedef std::map<std::string, Object> MapType;
    typedef std::list<Object> ListType;

    enum Type {
        TYPE_NONE,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_STRING,
        TYPE_MAP,
        TYPE_LIST
    };


	void CommonConstruct()
	{
		MapType* m_pM = new MapType;
		ListType* m_pL = new ListType;
	}
    /// Construct an empty object.
    Object()
      : t(TYPE_NONE), i(0), f(0.0), s()
    {
		CommonConstruct();
    }

    /// Copy an existing object.
    Object(const Object& m)
      : t(m.t), i(m.i), f(m.f), s(m.s)
    {
		CommonConstruct();
		*m_pMap = *m.m_pMap;
		*m_pList = *m.m_pList;
    }

    /// Set type to int, and value to v.
    Object(int v)
      : t(TYPE_INT), i(v), f(0.0), s()
    {
		CommonConstruct();
    }
    /// Set type to double, and value to v.
    Object(double v)
      : t(TYPE_FLOAT), i(0), f(v), s()
    {
		CommonConstruct();
    }
    /// Set type to std::string, and value to v.
    Object(const std::string& v)
      : t(TYPE_STRING), i(0), f(0.0), s(v)
    {
		CommonConstruct();
    }
    /// Set type to MapType, and value to v.
    Object(const MapType& v)
      : t(TYPE_MAP), i(0), f(0.0), s()
    {
		CommonConstruct();
		*m_pMap = v;
    }

    /// Set type to ListType, and value to v.
    Object(const ListType& v)
      : t(TYPE_LIST), i(0), f(0.0), s()
    {
		CommonConstruct();
		*m_pList = v;
    }

	~Object()
	{
		if (m_pMap)
			delete m_pMap;

		if (m_pList)
			delete m_pList;
	}

	///Assigns an object to another. Required for pointer member content to be copied correctly.
	Object& operator=(const Object& rhs)
	{
		f = rhs.f;
		i = rhs.i;
		s = rhs.s;
		t = rhs.t;
		*m_pMap = *rhs.m_pMap;
		*m_pList = *rhs.m_pList;
		return *this;
	}

    /// Check for equality with another Object.
    bool operator==(const Object& o) const
    {
        if (t != o.t) return false;
        switch(t) {
            case TYPE_NONE: return true;
            case TYPE_INT: return i == o.i;
            case TYPE_FLOAT: return f == o.f;
            case TYPE_STRING: return s == o.s;
            case TYPE_MAP: return *m_pMap == *o.m_pMap;
            case TYPE_LIST: return *m_pList == *o.m_pList;
        }
        return false;
    }

    /// Check for inequality with another Object.
    bool operator!=(const Object m) const
    {
        return !(*this == m);
    }

    /// Check for equality with a int.
    bool operator==(int v) const
    {
        return (t == TYPE_INT && i == v);
    }

    /// Check for inequality with a int.
    bool operator!=(int v) const { return !(*this == v); }

    /// Check for equality with a double.
    bool operator==(double v) const
    {
        return (t == TYPE_FLOAT && f == v);
    }

    /// Check for inequality with a double.
    bool operator!=(double v) const { return !(*this == v); }

    /// Check for equality with a std::string.
    bool operator==(const std::string& v) const
    {
        return (t == TYPE_STRING && s == v);
    }

    /// Check for inequality with a std::string.
    bool operator!=(const std::string& v) const { return !(*this == v); }

    /// Check for equality with a MapType.
    bool operator==(const MapType& v) const
    {
        return (t == TYPE_MAP && *m_pMap == v);
    }

    /// Check for inequality with a MapType.
    bool operator!=(const MapType& v) const { return !(*this == v); }

    /// Check for equality with a ListType.
    bool operator==(const ListType& v) const
    {
        return (t == TYPE_LIST && *m_pList == v);
    }

    /// Check for inequality with a ListType.
    bool operator!=(const ListType& v) const { return !(*this == v); }

    /// Clear all values.
    void Clear()
    {
        t = TYPE_NONE;
        s.erase();
        m_pMap->clear();
        m_pList->clear();
    }

    /// Get the current type.
    Type GetType() const { return t; }
    /// Check whether the current type is nothing.
    bool IsNone() const { return (t == TYPE_NONE); }
    /// Check whether the current type is int.
    bool IsInt() const { return (t == TYPE_INT); }
    /// Check whether the current type is double.
    bool IsFloat() const { return (t == TYPE_FLOAT); }
    /// Check whether the current type is std::string.
    bool IsString() const { return (t == TYPE_STRING); }
    /// Check whether the current type is MapType.
    bool IsMap() const { return (t == TYPE_MAP); }
    /// Check whether the current type is ListType.
    bool IsList() const { return (t == TYPE_LIST); }

    /// Retrieve the current value as a int.
    int AsInt() const throw (WrongTypeException)
    {
        if (t == TYPE_INT) return i;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a double.
    double AsFloat() const throw (WrongTypeException)
    {
        if (t == TYPE_FLOAT) return f;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a const std::string reference.
    const std::string& AsString() const throw (WrongTypeException)
    {
        if (t == TYPE_STRING) return s;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const std::string reference.
    std::string& AsString() throw (WrongTypeException)
    {
        if (t == TYPE_STRING) return s;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a const MapType reference.
    const MapType& AsMap() const throw (WrongTypeException)
    {
        if (t == TYPE_MAP) return *m_pMap;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const MapType reference.
    MapType& AsMap() throw (WrongTypeException)
    {
        if (t == TYPE_MAP) return *m_pMap;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a const ListType reference.
    const ListType& AsList() const throw (WrongTypeException)
    {
        if (t == TYPE_LIST) return *m_pList;
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const ListType reference.
    ListType& AsList() throw (WrongTypeException)
    {
        if (t == TYPE_LIST) return *m_pList;
        throw WrongTypeException();
    }

	/*operator= (Object& rhs)
	{
		t = rhs.
	}*/

protected:

    Type t;
    int i;
    double f;
    StringType s;
    MapType* m_pMap;
    ListType* m_pList;

};

} } // namespace Atlas::Message

#endif
