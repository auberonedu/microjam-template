#pragma once
namespace blo {

    class player {
        public:
            /**
             * player constructor
             */
            player();

            void update();

            bool hasSnack() const;
        private:
            bool _has_snack = true;
    };

}
