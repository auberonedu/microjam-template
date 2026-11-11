#pragma once
namespace blo {

    class shark;


    class player {
        public:
            /**
             * player constructor
             */
            player();

            void update(shark& target);

            bool hasSnack() const;
        private:
            bool _has_snack = true;
    };

}
