#include <SFML/Graphics.hpp>
#include "source/Window.hpp"
#include "source/Player.hpp"
#include "source/Event.hpp"
#include "source/Background.hpp"
#include "source/Sector.hpp"
#include "source/Leader.hpp"
#include "source/Interactions.hpp"
#include "source/DialogueBox.hpp"
#include "source/ObjectiveBox.hpp"
#include "source/Text.hpp"
#include "source/File.hpp"
#include "source/NPCs.hpp"
#include "source/Marc.hpp"
#include "source/Elf.hpp"
#include "source/Button.hpp"
#include "source/Soul.hpp"
#include "source/Credits.hpp"


Window* game = new Window(1280, 720, "Eternal Winter", 60);
Entity* dialogue_box = new DialogueBox("assets/ui.png", sf::Vector2i(0, 0), sf::Vector2i(1000, 128), 1.f, game->window);
Text dialogue("assets/MouldyCheeseRegular-WyMWG.ttf", 15, sf::IntRect(149, 197, 199, 255), "You: Welcome");
File dialogue_file("assets/leader_dialogue_1.txt");
Text obj_2("assets/MouldyCheeseRegular-WyMWG.ttf", 13, sf::IntRect(149, 197, 199, 255), "Talk with Leader of the Village");

void interaction(bool interacted, bool& talks, short& talks_with, int interlocutor, bool talked ) {
    if (interacted && !talked) {
        talks = true;
        talks_with = interlocutor;
        talked = true;
    }
}

void player_talks(bool& talks, short talks_with, int interlocutor, bool& talked, bool& finished_talking, std::string change_objective, bool& released) 
{
    if (talks)
    {
        game->window.draw(dialogue_box->sprite);
        game->window.draw(dialogue.text);
    }
    if (talks_with == interlocutor) {
        if (released && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            released = false;
            dialogue.set_text_string(dialogue_file.read_line(dialogue_file.file));

            if (!dialogue_file.has_content) {
                talks = false;
                finished_talking = true;
                talked = true;
                talks_with = 0;
                obj_2.set_text_string(change_objective);
            }
        }
    }

}

int main() {
    Event event;
    Entity* player = new Player("assets/entities.png", sf::Vector2i(0,0), sf::Vector2i(16, 16), 5.f);
    Entity* npc_leader = new Leader("assets/entities.png", sf::Vector2i(16, 0), sf::Vector2i(16, 16), 5.f);
    Entity* npc_marc = new Marc("assets/entities.png", sf::Vector2i(0, 16), sf::Vector2i(16, 16), 5.f);
    Entity* npc_elf = new Elf("assets/entities.png", sf::Vector2i(16, 16), sf::Vector2i(16, 16), 5.f);
    Entity* button_quit = new Button("assets/ui.png", sf::Vector2i(0, 129), sf::Vector2i(200, 100), 1.f, sf::Vector2i(200, 129), sf::Vector2i(200, 100));
    Entity* button_play = new Button("assets/ui.png", sf::Vector2i(0, 229), sf::Vector2i(200, 100), 1.f, sf::Vector2i(200, 229), sf::Vector2i(200, 100));
    Entity* button_resume = new Button("assets/ui.png", sf::Vector2i(0, 329), sf::Vector2i(200, 100), 1.f, sf::Vector2i(200, 329), sf::Vector2i(200, 100));
    Entity* soul = new Soul("assets/entities.png", sf::Vector2i(0, 33), sf::Vector2i(32,32), 2.f, game->window);
    Entity* credits = new Credits("assets/credits.png", sf::Vector2i(0, 0), sf::Vector2i(1280, 3160), 1, game->window);
    Sector sector;
    Text paused("assets/MouldyCheeseRegular-WyMWG.ttf", 64, sf::IntRect(136, 179, 181, 255), "Paused");
    Interactions player_interacted;
    Entity* objective_box = new ObjectiveBox("assets/ui.png", sf::Vector2i(1001, 0), sf::Vector2i(255, 255), 1.f, game->window);
    Text obj_1("assets/MouldyCheeseRegular-WyMWG.ttf", 16, sf::IntRect(136, 179, 181, 255), "Objectives:");
    Text floating("assets/MouldyCheeseRegular-WyMWG.ttf", 16, sf::IntRect(136, 179, 181, 255), "Press 'F' to interact");
    Text name("assets/MouldyCheeseRegular-WyMWG.ttf", 64, sf::IntRect(136, 179, 181, 255), "Eternal Winter");
    NPCs npc;
    bool released = true;
    bool has_just_changed_sector = true;
    Button* button_quit_d = dynamic_cast<Button*>(button_quit);
    Button* button_resume_d = dynamic_cast<Button*>(button_resume);
    Button* button_play_d = dynamic_cast<Button*>(button_play);
    Soul* soul_d = dynamic_cast<Soul*>(soul);
    player->is_in = sector.Menu;
    player->sprite.setPosition(2 * (player->sprite.getScale().x * player->sprite.getLocalBounds().width), 600);
    obj_1.text.setPosition(8, 8);
    obj_2.text.setPosition(8, 28);
    dialogue.text.setPosition(dialogue_box->sprite.getPosition().x + 16, dialogue_box->sprite.getPosition().y + 16);
    int old_sector = player->is_in;
    bool playing = false;
    while (game->window.isOpen() && !event.closed) {
  
        if (!game->window.hasFocus()) continue;
        if (event.paused) std::cout << event.paused;
        event.Loop(game->window, released);
        if (player->is_in == sector.Menu && !playing)
        {
            game->window.clear(sf::Color::Black);
            name.text.setPosition((game->window.getSize().x / 2) - (name.text.getLocalBounds().width / 2), game->window.getSize().y - (20 * (name.text.getLocalBounds().height / 2)));
            game->window.draw(name.text);
                 if (button_play_d) {
                     button_play_d->update(button_play_d->sprite, game->window);
                if (button_play_d->is_clicked) {
                    playing = true;
                    player->is_in = sector.Village;
                }
                button_play_d->sprite.setPosition((game->window.getSize().x / 2) - (button_play_d->sprite.getLocalBounds().width / 2), game->window.getSize().y - (8 * (button_play_d->sprite.getLocalBounds().height / 2)));
            }
            if (button_quit_d) {
                button_quit_d->update(button_quit->sprite, game->window);
                if (button_quit_d->is_clicked) event.closed = true;
                button_quit->sprite.setPosition((game->window.getSize().x / 2) - (button_quit->sprite.getLocalBounds().width / 2), game->window.getSize().y - (4 * (button_quit->sprite.getLocalBounds().height / 2)));
            }
            game->window.display();
        }
        if (!playing) continue;
        else {
            if (soul_d->is_destroyed) {
                game->window.clear(sf::Color::Black);
                game->window.draw(credits->sprite);
                credits->sprite.move(0, -0.5f);
                if (credits->sprite.getPosition().y + (credits->sprite.getLocalBounds().height - 155) <= 0)
                    event.closed = true;
                else goto display;
            }
            if (player->is_in == sector.Pause_Menu)
            {
                game->window.clear(sf::Color::Black);
                paused.text.setPosition((game->window.getSize().x / 2) - (paused.text.getLocalBounds().width / 2), game->window.getSize().y - (20 * (paused.text.getLocalBounds().height / 2)));
                if (button_resume_d) {
                    button_resume_d->update(button_resume->sprite, game->window);
                    if (button_resume_d->is_clicked) {
                        event.paused = false;
                        player->is_in = old_sector;
                    }
                    button_resume->sprite.setPosition((game->window.getSize().x / 2) - (button_resume->sprite.getLocalBounds().width / 2), game->window.getSize().y - (8 * (button_resume->sprite.getLocalBounds().height / 2)));
                }
                if (button_quit_d) {
                    button_quit_d->update(button_quit->sprite, game->window);
                    if (button_quit_d->is_clicked) event.closed = true;
                    button_quit->sprite.setPosition((game->window.getSize().x / 2) - (button_quit->sprite.getLocalBounds().width / 2), game->window.getSize().y - (4 * (button_quit->sprite.getLocalBounds().height / 2)));
                }
                game->window.draw(paused.text);
                goto display;
            }
            game->window.clear(sf::Color::Blue);


            sector.manager(game->window, player->is_in, npc_leader->sprite, npc_marc->sprite, npc_elf->sprite, soul->sprite);

            player->update(game->window);
            game->window.draw(player->sprite);

            if (player->is_in == sector.Village && !npc_leader->talked) {
                interaction(player_interacted.with_npc(player->sprite, npc_leader->sprite, game->window, floating.text), player->talks, player->talks_with, npc.Leader, npc_leader->talked);
                player_talks(player->talks, player->talks_with, npc.Leader, npc_leader->talked, player->finished_talking, "Meet with a team", released);

            }
            if (player->is_in == sector.Field_2 && !npc_marc->talked) {
                if (has_just_changed_sector)
                {
                    has_just_changed_sector = false;
                    dialogue_file.change_file("assets/marc_dialogue_1.txt");
                }
                interaction(player_interacted.with_npc(player->sprite, npc_marc->sprite, game->window, floating.text), player->talks, player->talks_with, npc.Marc, npc_marc->talked);
                player_talks(player->talks, player->talks_with, npc.Marc, npc_marc->talked, player->finished_talking, "Go to elvish towers", released);

            }
            if (player->is_in == sector.Cave && !npc_elf->talked) {
                if (!has_just_changed_sector)
                {
                    has_just_changed_sector = true;
                    dialogue_file.change_file("assets/elf_dialogue_1.txt");
                }
                interaction(player_interacted.with_npc(player->sprite, npc_elf->sprite, game->window, floating.text), player->talks, player->talks_with, npc.Elf, npc_elf->talked);
                player_talks(player->talks, player->talks_with, npc.Elf, npc_elf->talked, player->finished_talking, "Free the soul of God", released);

            }            
            if (player->is_in == sector.Tower) {
                if (!soul_d->is_destroyed && soul_d) soul_d->rotate();
                if (player_interacted.with_npc(player->sprite, soul->sprite, game->window, floating.text)) {
                    soul_d->is_destroyed = true;
                    obj_2.set_text_string("");
                }

            }
            if (event.paused) {
                old_sector = player->is_in;
                player->is_in = sector.Pause_Menu;
            }

            game->window.draw(objective_box->sprite);
            game->window.draw(obj_1.text);
            game->window.draw(obj_2.text);

        display:
            game->window.display();
        }
    }
    delete game;
    delete player;
    delete npc_leader;
    delete npc_marc;
    delete npc_elf;
    delete button_play;
    delete button_quit;
    delete button_resume;
    delete soul;
    delete credits;
    return 0;
}