build/grids/adc.o: avrlib/adc.cc avrlib/adc.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h
build/grids/random.o: avrlib/random.cc avrlib/random.h avrlib/base.h
build/grids/serial.o: avrlib/serial.cc avrlib/serial.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h avrlib/gpio.h avrlib/timer.h \
 avrlib/ring_buffer.h
build/grids/string.o: avrlib/string.cc avrlib/string.h avrlib/base.h
build/grids/time.o: avrlib/time.cc avrlib/time.h avrlib/base.h \
 avrlib/timer.h avrlib/avrlib.h avrlib/size_to_type.h
build/grids/wii_nunchuk.o: avrlib/devices/wii_nunchuk.cc \
 avrlib/devices/wii_nunchuk.h avrlib/i2c/i2c.h avrlib/gpio.h \
 avrlib/avrlib.h avrlib/base.h avrlib/size_to_type.h avrlib/timer.h \
 avrlib/ring_buffer.h
build/grids/clock.o: grids/clock.cc grids/clock.h avrlib/base.h \
 grids/pattern_generator.h avrlib/random.h grids/hardware_config.h \
 avrlib/gpio.h avrlib/avrlib.h avrlib/size_to_type.h avrlib/timer.h \
 avrlib/parallel_io.h avrlib/serial.h avrlib/ring_buffer.h avrlib/spi.h \
 grids/resources.h avrlib/resources_manager.h
build/grids/grids.o: grids/grids.cc avrlib/adc.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h avrlib/boot.h avrlib/time.h \
 avrlib/timer.h avrlib/op.h avrlib/watchdog_timer.h grids/clock.h \
 grids/pattern_generator.h avrlib/random.h grids/hardware_config.h \
 avrlib/gpio.h avrlib/parallel_io.h avrlib/serial.h avrlib/ring_buffer.h \
 avrlib/spi.h grids/midi.h
build/grids/midi.o: grids/midi.cc grids/midi.h avrlib/base.h \
 grids/hardware_config.h avrlib/gpio.h avrlib/avrlib.h \
 avrlib/size_to_type.h avrlib/timer.h avrlib/parallel_io.h \
 avrlib/serial.h avrlib/ring_buffer.h avrlib/spi.h
build/grids/pattern_generator.o: grids/pattern_generator.cc \
 grids/pattern_generator.h avrlib/base.h avrlib/random.h \
 grids/hardware_config.h avrlib/gpio.h avrlib/avrlib.h \
 avrlib/size_to_type.h avrlib/timer.h avrlib/parallel_io.h \
 avrlib/serial.h avrlib/ring_buffer.h avrlib/spi.h avrlib/op.h \
 grids/resources.h avrlib/resources_manager.h
build/grids/resources.o: grids/resources.cc grids/resources.h \
 avrlib/base.h avrlib/resources_manager.h
