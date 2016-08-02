/*
Connor Armand du Plooy 2016

Design Patterns : Factory (WRAPPERS - WRAPPERS EVERYWHERE)
Participants :
      Concrete Factory/Creator (Athos/Aramis/Porthos Constructors)
      Abstract Factory (Musketeer)

      Concrete Product (Athos/Aramis/Porthos Instance)
      Abstract Product (createMuskteer) // sort of.
Look up the definitions. These short examples are only for review.
*/

#include <iostream>

/*
This is an example of the factory design pattern.

It is a wrapper around constructors which makes it easier to create classes and edit code since
everything is in one place.
It uses the three musketeers as an example.
*/
class Musketeer;

class Athos;
class Aramis;                 //These are forward declarations. They aren't required in this example but they aren't a bad idea either.
class Porthos;

class Musketeer{ //This is a factory.
      public:
            static Musketeer *createMusketeer(short type); //So I can do Musketeer::createMusketeer

            /*
            #JustCompilerThings: (Don't need to know this)

            Basically what the static method is doing is instansiating the createMusketeer function into the executable.
            iow , there is some memory address which if executed will be the createMusketeer function. The emote function is not
            instansiated ( not in this class at least) in the normal sense because it receives a pointer value of NULL. Speaking of which
            I'm guessing the virtual func = 0 is so the compiler doesn't call a rubbish address but why the hell would it not use NULL.

            CMasterRace , CMasterRace , CMasterRace

            This does not happen to void emote because it is a virtual ( overridden ) function and not static (just look it up).
            */

            virtual void emote() = 0; // = 0 so the compiler doesn't freak out
            /*
            Every musketeer has a special emote.

            Wrapping the constructor to the child classes of Musketeer makes managing the code easier.
            If you instansiate a Athos class of the parent class Musketeer it's emote will be different to the emote of Aramis ( also a child class of Musketeer).
            Should you want to change the constructor of either of these three child classes the code only needs to be changed in the constructor wrapper which is createMusketeer.
            */
};

class Athos : public Musketeer{
      public:
            void emote(){
                  std::cout << "The fact is, that they said to me-you are M. d’Artagnan. I replied-do you think so?My guards said they were sure of it. I did not wish to contradict them; besides, I might be mistaken." << std::endl;
            }

};

class Aramis : public Musketeer{
      public:
            void emote(){
                  std::cout << "He takes his drinking very seriously. Not to worry, he’ll be his usual charming self by morning." << std::endl;
            }

};

class Porthos : public Musketeer{
      public:
            void emote(){
                  std::cout << "Little pimple... meet me behind the Luxembourg at 1 o'clock and bring a long wooden box." << std::endl;
            }

};

Musketeer *Musketeer::createMusketeer(short type){  //NB The constructor wrapper itself needs to be below the other child classes. Otherwise we get Incomplete Type errors.
      switch (type) {
            case 1:
                  return new Athos;
            case 2:
                  return new Aramis;
            case 3:
                  return new Porthos;
            /*
             No breaks are required after each case because we immediately return ; Thus fall through is impossible.
            */
            default:
                  return NULL; //This is basic C. NULL is the equivalent of an error return code.
      }
}
void drawLine(){
      std::cout << "_________________________________________________________" << std::endl;
}

int main(){
      int *a = new *int(6);
      Musketeer *athos = Musketeer::createMusketeer(1);
      athos->emote();
      drawLine();

      Musketeer *aramis = Musketeer::createMusketeer(2);
      aramis->emote();
      drawLine();

      Musketeer *pathos = Musketeer::createMusketeer(3);
      pathos->emote();
      drawLine();

      return 0;
}
