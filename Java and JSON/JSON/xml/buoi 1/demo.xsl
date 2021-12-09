<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0 " xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<title>Bảng điểm</title>
				<style>
					table {
						margin: 0 auto;
						border-collapse: collapse;
						border: 3px inset black;
					}

					td {
						text-align: center;
						padding: 4px;
						border: 2px inset black;
					}
				</style>
			</head>
			<body>
				<table>
					<caption style="color: red; font-weight: bold; font-size: 24px;">Điểm tổng kết môn học Vật lý</caption>
					<tr>
						<td rowspan="2">STT</td>
						<td rowspan="2">Mã học sinh</td>
						<td rowspan="2" style="width: 150px;">Họ và tên</td>
						<td colspan="2" style="width: 85px;">Điểm hệ số</td>
						<td rowspan="2" class="dau">Điểm TBKT</td>
						<td rowspan="2">Điểm thi</td>
						<td rowspan="2" class="dau">Điểm TBMH</td>
					</tr>
					<tr class="hs">
						<td colspan="">HS1</td>
						<td>HS2</td>
					</tr>
					<tbody>
						<xsl:for-each select="tongKetMon/thongtinHocSinh">
							<tr>
								<td>
									<xsl:value-of select="id" />
								</td>
								<td>
									<xsl:value-of select="mahs" />
								</td>
								<td>
									<xsl:value-of select="name" />
								</td>
								<td>
									<xsl:value-of select="diemHeSo/hs1" />
								</td>
								<td>
									<xsl:value-of select="diemHeSo/hs2" />
								</td>
								<td>
									<xsl:value-of select="tbkt" />
								</td>
								<td>
									<xsl:value-of select="thi" />
								</td>
								<td>
									<xsl:value-of select="tbmon" />
								</td>
							</tr>
						</xsl:for-each>
					</tbody>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>