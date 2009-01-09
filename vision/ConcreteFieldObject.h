#ifndef ConcreteFieldObject_h_defined
#define ConcreteFieldObject_h_defined

// Forward Reference
class ConcreteFieldObject;

// STL libraries
#include <ostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

// Local headers
#include "FieldConstants.h"
#include "ConcreteLandmark.h"
#define CONCRETE_FIELD_OBJECT_START_ID 30
enum fieldObjectID {
    BLUE_GOAL_LEFT_POST = CONCRETE_FIELD_OBJECT_START_ID,
    BLUE_GOAL_RIGHT_POST,
    YELLOW_GOAL_LEFT_POST,
    YELLOW_GOAL_RIGHT_POST,
    BLUE_GOAL_POST,
    YELLOW_GOAL_POST,
    YELLOW_BLUE_BEACON,
    BLUE_YELLOW_BEACON,
    BLUE_ARC,
    YELLOW_ARC,
    UNKNOWN_FIELD_OBJECT
};

class ConcreteFieldObject : public ConcreteLandmark {
    /* Constructors are private because no one should ever have to create more
     * concrete field objects. All of them are defined as constant static
     * members of this class.
     */
private:
    ConcreteFieldObject(const float fieldX, const float fieldY,
                        const fieldObjectID _id);
    // copy constructor
    ConcreteFieldObject(const ConcreteFieldObject&);

public: // Constants
    static const int NUM_BLUE_GOAL_POSTS = 2;
    static const int NUM_YELLOW_GOAL_POSTS = 2;
    static const int NUM_FIELD_OBJECTS = NUM_BLUE_GOAL_POSTS +
        NUM_YELLOW_GOAL_POSTS;

public:
    virtual ~ConcreteFieldObject();

    friend std::ostream& operator<< (std::ostream &o,
                                     const ConcreteFieldObject &fo)
    {
        return o << fo.toString();
    }

    ////////////////////////////////////////////////////////////
    // GETTERS
    ////////////////////////////////////////////////////////////
    const fieldObjectID getID() const { return id; }

    virtual const string toString() const;

    bool isAbstract(ConcreteFieldObject fo);

// Static member variables
public:
    static const ConcreteFieldObject blue_goal_left_post,
                    blue_goal_right_post,
                    yellow_goal_left_post,
                    yellow_goal_right_post,
                    blue_goal_post,
                    yellow_goal_post;

    static const ConcreteFieldObject* concreteFieldObjectList[
        NUM_FIELD_OBJECTS];

private:
    static const ConcreteFieldObject* BLUE_GOAL_POSTS[NUM_BLUE_GOAL_POSTS];
    static const ConcreteFieldObject* YELLOW_GOAL_POSTS[NUM_YELLOW_GOAL_POSTS];

public:
    static const list <const ConcreteFieldObject*> blueGoalPosts;
    static const list <const ConcreteFieldObject*> yellowGoalPosts;

private: // Instance variables recording location on field and identifier
    fieldObjectID id;

}; // class ConcreteFieldObject

#endif // ConcreteFieldObject_h_defined