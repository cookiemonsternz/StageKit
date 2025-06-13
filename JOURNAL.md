# Stagekit - Journal 1 - 13/06/2025

Alrighty!
I am pumped after just submitting my previous Highway project (Lens Board) and am super hyped to get started on this one.

Today I'm literally just going to braindump for this journal, and maybe come up with a proper idea of what I'm doing. 

I'll do a summary at the end of this journal with the general idea + diagrams, so skip to there if you don't want to hear this absolute atrocity of a writing extravaganza.

## Brainstorm

Mini stage lighting kitset kinda thing
it'll have a bunch of lights, trusses, and maybe a little fog machine run by a rpi zero 2 w.

Truss should be either buyable (aliexpress) or printable, so i'll need a solution for that

maybe straight segments buyable in one size and then just make brackets and stuff for everything else that are 3d printable

don't have a resin printer and that will probably be necessary for this, so will need to fab enough stuff through jlc3dp

actual spec-

Spi or i2c - pros and cons

nvm, spi has limitations with num devices (like max 16 slaves probs + takes a pin per slave i think) :skull:
absolutely not
i2c it is

Do they just send channel data like dmx, or do I try and establish more of a actual data connection between like rp2040's or something

Would prefer something not as expensive as rp2040
~1 usd per chip might be much?
would probs be like 5nz per fixture
hmmm
16 * 5 = 80
Would prefer closer to $3 per fixture
we'll see

Maybe those little microcontrollers with like 8 pins

but also will need a decent number of pins for e.g moving lights

it would be good to be able to use multiple chips

but id really want to write usb from scratch

mayb i2c makes it easy? research later

Size is important, how big should stuff be?
I want a consistent scale, so maybe doing an actual to scale value would be good

Megapointe is 64 cm tall, so maybe 1:10, so 6.4 cm?
how big would a stage be at that height?

mayfair proscenium is 10.6m wide, 4.5 high, and 6m deep
at 1:10 that would be 106x45x60cm

bit big
slimpar size is 253 x 98 x 290 mm
would be 25x9.8x29

might be pushing feasibility for pcb + case + leds

dunno
seems possible??????
pcb is 1.6, light might be 5mm +- 2mm, that leaves between 1.2 and 3.2 mm wall / other size
doable

wouldn't want to go smaller, so min 1:10 scale.

cannot find any truss thingys on aliexpress, keep looking later but maybe all 3dp

makes it easier tbh

if its 1:10 scale, how thick are mounting things on eurotruss?

Eurotruss ST is 30mm rad
would be 3mm
so 6mm diam
could be fine? - check resin print tolerances

its fine

inter big one things might need to be thicker tho, but thats fine

Clamps?

Maybe just have hooks on the lights, doesn't really need to be detachable or anything, they're mostly going to be hung the same way

going to sleep now, will cont. morgens