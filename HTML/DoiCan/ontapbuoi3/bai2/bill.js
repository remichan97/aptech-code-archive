function tinhtien() {
    var hoadon = parseInt(document.getElementById('tien').value);
    var boa = parseInt(document.getElementById('tienboa').value);
    var quanso = parseInt(document.getElementById('songuoi').value);
    var sotienphaitra = (hoadon + (hoadon * (boa / 100))) / quanso;
    sotienphaitra = sotienphaitra.toFixed(2);
    alert('Each person will pay $' + sotienphaitra + '.')
}
