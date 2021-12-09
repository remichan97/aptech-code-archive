function tinhToan(opr) {
	with (mth) {
		var a, b, r;
		a = number1.value;
		b = number2.value;
		r = ketQua;
		if (opr === '+') {
			r.value = eval(a) + eval(b);
		} else if (opr === '-') {
			r.value = eval(a) - eval(b);
		} else if (opr === '*') {
			r.value = eval(a) * eval(b);
		} else if (opr === '/') {
			r.value = eval(a) / eval(b);
		}
	}
}