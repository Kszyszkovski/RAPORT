from __future__ import annotations

import sigvis as m


def mean(x):
    return sum(x) / len(x)

def test():
    print(help(m.save_plot))
    print(help(m.save_plot_xy))
    print(help(m.gen_sin))

    expected = [1, 4, 9, 16]
    dft = m.dft(expected, 4)
    dft_r = [e.get_real() for e in dft]
    dft_i = [e.get_imaginary() for e in dft]
    actual = m.idft(dft, 4)
    diff = mean(list(abs(x-y) for x, y in zip(expected, actual)))
    m.save_plot("img/dft/expected.jpg", [expected], ["initial values"])
    m.save_plot("img/dft/dft_real_imag.jpg", [dft_r, dft_i], ["real", "imaginary"], "DFT and IDFT", "index", "value")
    m.save_plot("img/dft/actual.jpg", [actual])
    assert diff < 1

    sig_sin = m.gen_sin(1, 1, 10)
    m.save_plot_xy("img/generated/sin1.jpg", sig_sin[0], sig_sin[1], "Sine freq = 1Hz amp = 1 res = 10", "time [s]", "sin")
    assert len(sig_sin[0]) == 10 and len(sig_sin[1]) == 10

    sig_sin = m.gen_sin(3, 2.5, 100, 2)
    m.save_plot_xy("img/generated/sin2.jpg", sig_sin[0], sig_sin[1], "Sine freq = 2.5Hz amp = 3 res = 100 cycles = 2", "time [s]", "sin")
    assert len(sig_sin[0]) == 200 and len(sig_sin[1]) == 200

    sig_cos = m.gen_cos(4, 10, 100, 4)
    m.save_plot_xy("img/generated/cos.jpg", sig_cos[0], sig_cos[1], "Cosine freq = 10Hz amp = 4 res = 100 cycles = 4", "time [s]", "cos")
    assert len(sig_cos[0]) == 400 and len(sig_cos[1]) == 400

    sig_saw = m.gen_saw(4, 10, 100, 3)
    m.save_plot_xy("img/generated/saw.jpg", sig_saw[0], sig_saw[1], "Saw freq = 10Hz amp = 4 res = 100 cycles = 3", "time [s]", "saw")
    assert len(sig_saw[0]) == 300 and len(sig_saw[1]) == 300

    sig_square = m.gen_square(4, 1, 100, 5)
    m.save_plot_xy("img/generated/square.jpg", sig_square[0], sig_square[1], "Square freq = 1Hz amp = 4 res = 100 cycles = 5", "time [s]", "square")
    assert len(sig_square[0]) == 500 and len(sig_square[1]) == 500
