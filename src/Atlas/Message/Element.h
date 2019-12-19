// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Stefanus Du Toit, Karsten-O. Laux and Al Riddoch

// $Id$

#ifndef ATLAS_MESSAGE_ELEMENT_H
#define ATLAS_MESSAGE_ELEMENT_H

#include <Atlas/Exception.h>
#include <Atlas/float.h>

#include <string>
#include <map>
#include <vector>

namespace Atlas { namespace Message {

/// An exception class issued when the wrong type is requested in as().
class WrongTypeException : public Atlas::Exception
{
  public:
    WrongTypeException() noexcept : Atlas::Exception("Wrong Message::Element type") { }
};

class Element;

typedef std::int64_t IntType;
typedef double FloatType;
typedef void * PtrType;
typedef std::string StringType;
typedef std::map<std::string, Element> MapType;
typedef std::vector<Element> ListType;

/**
 * Multi-type container.
 *
 * For complex type (string, list and map) we try to keep as much on the stack as possible.
 */
class Element
{
public:
    enum Type {
        TYPE_NONE,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_PTR,
        TYPE_STRING,
        TYPE_MAP,
        TYPE_LIST
    };

private:

    /// Clear all values.
    void clear(Type new_type = TYPE_NONE);

public:
    /// Construct an empty object.
    Element()
      : t(TYPE_NONE)
    {
    }

    ///
    ~Element()
    {
        clear();
    }

    /// Copy an existing object.
    Element(const Element& obj);

    /// Move an existing object.
    /// The existing Element will have its type set to "None".
    Element(Element&& obj) noexcept;

    /// Set type to int, and value to v.
	Element(int v)
			: t(TYPE_INT), i(v)
	{
	}

    Element(long v)
      : t(TYPE_INT), i(v)
    {
    }

    /// Set type to int, and value to v.
    Element(bool v)
      : t(TYPE_INT), i(v)
    {
    }

    /// Set type to int, and value to v.
    Element(long long v)
      : t(TYPE_INT), i(v)
    {
    }

    /// Set type to double, and value to v.
    Element(float v)
      : t(TYPE_FLOAT), f(v)
    {
    }   

    /// Set type to double, and value to v.
    Element(FloatType v)
      : t(TYPE_FLOAT), f(v)
    {
    }

    /// Set type to PtrType, and value to v.
    Element(PtrType v)
      : t(TYPE_PTR), p(v)
    {
    }

    /// Set type to std::string, and value to v.
    Element(const char* v)
      : t(TYPE_STRING)
    {
	  new(&s) StringType(v);
    }

    /// Set type to std::string, and value to v.
    Element(const StringType& v)
      : t(TYPE_STRING)
    {
	    new(&s) StringType(v);
	}
    /// Set type to std::string, and move v.
    Element(StringType&& v)
      : t(TYPE_STRING)
    {
		new(&s) StringType(std::move(v));
    }

    /// Set type to MapType, and value to v.
    Element(const MapType& v)
      : t(TYPE_MAP)
    {
	    new(&m) MapType(v);
    }
    /// Set type to MapType, and move v.
    Element(MapType&& v)
      : t(TYPE_MAP)
    {
		new(&m) MapType(std::move(v));
    }

    /// Set type to ListType, and value to v.
    Element(const ListType& v)
      : t(TYPE_LIST)
    {
		new(&l) ListType(v);
    }
    /// Set type to ListType, and move v.
    Element(ListType&& v)
      : t(TYPE_LIST)
    {
		new(&l) ListType(std::move(v));
    }

    /// overload assignment operator !
    Element& operator=(const Element& obj);

    /**
     * The object being moved from will have its type set to "None".
     * @param obj
     * @return
     */
    Element& operator=(Element&& obj) noexcept;

	Element& operator=(int v)
	{
		if (TYPE_INT != t)
		{
			clear(TYPE_INT);
		}
		i = v;
		return *this;
	}

    Element& operator=(long v)
    {
      if (TYPE_INT != t)
      {
        clear(TYPE_INT);
      }
      i = v;
      return *this;
    }

    Element& operator=(bool v) 
    {
      if (TYPE_INT != t)
      {
        clear(TYPE_INT);
      }
      i = v;
      return *this;
    }

    Element& operator=(long long v)
    {
      if (TYPE_INT != t)
      {
        clear(TYPE_INT);
      }
      i = v;
      return *this;
    }

    Element& operator=(float v) 
    {
      if (TYPE_FLOAT != t)
      {
        clear(TYPE_FLOAT);
      }
      f = v;
      return *this;
    }

    Element& operator=(FloatType v) 
    {
      if (TYPE_FLOAT != t)
      {
        clear(TYPE_FLOAT);
      }
      f = v;
      return *this;
    }

    Element& operator=(PtrType v) 
    {
      if (TYPE_PTR != t)
      {
        clear(TYPE_PTR);
      }
      p = v;
      return *this;
    }

    Element& operator=(const char * v) 
    {
      if (TYPE_STRING != t)
      {
        clear(TYPE_STRING);
        new(&s) StringType(v);
      } else {
		  String() = v;
      }
      return *this;
    }

    Element& operator=(const StringType & v) 
    {
		if (TYPE_STRING != t)
		{
			clear(TYPE_STRING);
			new(&s) StringType(v);
		} else {
			String() = v;
		}
		return *this;
    }

    Element& operator=(StringType && v)
    {
		if (TYPE_STRING != t)
		{
			clear(TYPE_STRING);
			new(&s) StringType(std::move(v));
		} else {
			String() = std::move(v);
		}
		return *this;
    }

    Element& operator=(const MapType & v) 
    {
      if (TYPE_MAP != t)
      {
        clear(TYPE_MAP);
        new(&m) MapType(v);
      } else {
      	Map() = v;
      }
	  return *this;
    }

    Element& operator=(MapType && v)
    {
		if (TYPE_MAP != t)
		{
			clear(TYPE_MAP);
			new(&m) MapType(std::move(v));
		} else {
			Map() = std::move(v);
		}
		return *this;
    }

    Element& operator=(const ListType & v) 
    {
		if (TYPE_LIST != t)
		{
			clear(TYPE_LIST);
			new(&l) ListType(v);
		} else {
			List() = v;
		}
        return *this;
    }

    Element& operator=(ListType && v)
    {
		if (TYPE_LIST != t)
		{
			clear(TYPE_LIST);
			new(&l) ListType(std::move(v));
		} else {
			List() = std::move(v);
		}
		return *this;
    }

    /// Check for equality with another Element.
    bool operator==(const Element& o) const;

    /// Check for inequality with anything we can check equality with
    template<class C>
    bool operator!=(C c) const
    {
        return !(*this == c);
    }

	/// Check for equality with a int.
	bool operator==(int v) const
	{
		return (t == TYPE_INT && i == v);
	}

	/// Check for equality with a int.
	bool operator==(long v) const
	{
		return (t == TYPE_INT && i == v);
	}

	/// Check for equality with a int.
	bool operator==(long long v) const
	{
		return (t == TYPE_INT && i == v);
	}

	/// Check for equality with a double.
    bool operator==(FloatType v) const
    {
      return t == TYPE_FLOAT && Equal(f, v);
    }

    /// Check for equality with a pointer.
    bool operator==(PtrType v) const
    {
      return t == TYPE_PTR && p == v;
    }

    /// Check for equality with a const char *.
    bool operator==(const char * v) const
    {
      if(t == TYPE_STRING)
        return (String() == v);
      return false;
    }

    /// Check for equality with a std::string.
    bool operator==(const StringType& v) const
    {
      if(t == TYPE_STRING)
		  return (String() == v);
      return false;
    }

    /// Check for equality with a MapType.
    bool operator==(const MapType& v) const
    {
      if(t == TYPE_MAP)
		  return (Map() == v);
      return false;
    }

    /// Check for equality with a ListType.
    bool operator==(const ListType& v) const
    {
      if (t == TYPE_LIST)
		  return (List() == v);
      return false;
    }

    /// Get the current type.
    Type getType() const { return t; }
    /// Check whether the current type is nothing.
    bool isNone() const { return (t == TYPE_NONE); }
    /// Check whether the current type is int.
    bool isInt() const { return (t == TYPE_INT); }
    /// Check whether the current type is double.
    bool isFloat() const { return (t == TYPE_FLOAT); }
    /// Check whether the current type is pointer.
    bool isPtr() const { return (t == TYPE_PTR); }
    /// Check whether the current type is numeric.
    bool isNum() const { return ((t == TYPE_FLOAT) || (t == TYPE_INT)); }
    /// Check whether the current type is std::string.
    bool isString() const { return (t == TYPE_STRING); }
    /// Check whether the current type is MapType.
    bool isMap() const { return (t == TYPE_MAP); }
    /// Check whether the current type is ListType.
    bool isList() const { return (t == TYPE_LIST); }

    /// Retrieve the current value as a int.
    IntType asInt() const
    {
        if (t == TYPE_INT) return i;
        throw WrongTypeException();
    }
    IntType Int() const
    {
        return i;
    }
    /// Retrieve the current value as a double.
    FloatType asFloat() const
    {
        if (t == TYPE_FLOAT) return f;
        throw WrongTypeException();
    }
    FloatType Float() const
    {
        return f;
    }
    /// Retrieve the current value as a pointer.
    PtrType asPtr() const
    {
        if (t == TYPE_PTR) return p;
        throw WrongTypeException();
    }
    PtrType Ptr() const
    {
        return p;
    }
    /// Retrieve the current value as a number.
    FloatType asNum() const
    {
        if (t == TYPE_FLOAT) return f;
        if (t == TYPE_INT) return FloatType(i);
        throw WrongTypeException();
    }
    /// Retrieve the current value as a const std::string reference.
    const std::string& asString() const
    {
        if (t == TYPE_STRING) return String();
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const std::string reference.
    std::string& asString()
    {
		if (t == TYPE_STRING) return String();
        throw WrongTypeException();
    }
    const StringType& String() const
    {
        return *((const StringType*)s);
    }
    StringType& String()
    {
		return *((StringType*)s);
    }

    /**
     * Moves the string out of the Element.
     *
     * This will leave an empty string in the Element.
     * @return
     */
    StringType&& moveString() {
        if (t != TYPE_STRING) throw WrongTypeException();
        return std::move(String());
    }

    /// Retrieve the current value as a const MapType reference.
    const MapType& asMap() const
    {
        if (t == TYPE_MAP) return Map();
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const MapType reference.
    MapType& asMap()
    {
        if (t == TYPE_MAP) return Map();
        throw WrongTypeException();
    }
    const MapType& Map() const
    {
        return *((const MapType*)m);
    }
    MapType& Map()
    {
		return *((MapType*)m);
    }

    /**
     * Moves the map out of the Element.
     *
     * This will leave an empty map in the Element.
     * @return
     */
    MapType&& moveMap() {
        if (t != TYPE_MAP) throw WrongTypeException();
        return std::move(Map());
    }

    /// Retrieve the current value as a const ListType reference.
    const ListType& asList() const
    {
        if (t == TYPE_LIST) return List();
        throw WrongTypeException();
    }
    /// Retrieve the current value as a non-const ListType reference.
    ListType& asList()
    {
        if (t == TYPE_LIST) return List();
        throw WrongTypeException();
    }
    const ListType& List() const
    {
        return *((const ListType*)l);
    }
    ListType& List()
    {
		return *((ListType*)l);
    }

    /**
     * Moves the list out of the Element.
     *
     * This will leave an empty list in the Element.
     * @return
     */
    ListType&& moveList() {
        if (t != TYPE_LIST) throw WrongTypeException();
        return std::move(List());
    }

    static const char * typeName(Type);

protected:

    Type t;
    union {
      IntType i;
      FloatType f;
      void* p;
      /**
       * The string, list and map types are kept on the stack, but since C++ doesn't allow unions with non-POD structs we need
       * to declare them as opaque char arrays and then call destructors and constructors manually.
       */
      char s[sizeof(StringType)];
      char m[sizeof(MapType)];
      char l[sizeof(ListType)];
    };
};

} } // namespace Atlas::Message


#endif // ATLAS_MESSAGE_ELEMENT_H
