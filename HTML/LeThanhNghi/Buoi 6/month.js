function checkMonth() {
	with (frm) {
		var mth = month.value;
		var year;
		switch (mth) {
			case '2':
				year = prompt('You selected February! Please enter a year to calculate:');
				while (year.length <= 0 || year % 1 != 0) {
					year = prompt('The previous input is either empty or is invalid! Please enter another year to calculate:');
				}
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
					alert('February in the given year has 29 days');
				} else {
					alert('February in the given year has 28 days');
				}
				break;
			case '1': case '3': case '5': case '7': case '8': case '10': case '12':
				alert('This month has 31 days!');
				break;
			default:
				alert('This month has 30 days!');
				break;
		}
	}
}