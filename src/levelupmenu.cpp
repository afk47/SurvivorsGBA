#include "levelupmenu.h"
#include "bn_keypad.h"
#include "bn_string.h"
#include "bn_math.h"

LevelUpMenu::LevelUpMenu(bn::sprite_text_generator textGenerator,int level)
    : m_TextGenerator(textGenerator)
{

}

void LevelUpMenu::update()
{
    input();

    m_TextSprites.clear();
    m_TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);
    m_TextGenerator.generate(0,-10,"Level up!", m_TextSprites);
    m_TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);
    m_TextGenerator.generate(-40,0,"Upgrade 1",m_TextSprites);
    m_TextGenerator.generate(-40,10,"Upgrade 2",m_TextSprites);
    m_TextGenerator.generate(-40,20,"Upgrade 3",m_TextSprites);
    //Cursor
    m_TextGenerator.generate(-55,10*m_Selection,"->",m_TextSprites);


}

void LevelUpMenu::input(){

    if(bn::keypad::up_pressed()){
        m_Selection -= 1;
        m_Selection = m_Selection < 0 ? 2 : m_Selection;
    }
    if(bn::keypad::down_pressed()){
        m_Selection += 1;
        m_Selection = m_Selection > 2 ? 0 : m_Selection;
    }

    if(bn::keypad::a_pressed()){
        m_TextGenerator.generate(10,10*m_Selection,"✓",m_TextSprites);
        //upgrade(m_Selection);
    }
}

void LevelUpMenu::upgrade(int selection){
    switch(selection){
    case 0:     break;
    case 1:     break;
    case 2:     break;
    default:    break;
    }
}
