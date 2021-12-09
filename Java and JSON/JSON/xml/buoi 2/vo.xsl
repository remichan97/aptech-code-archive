<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"> 
	<xsl:template match="/">
		<html>
			<head>
				<title>value-of</title>
			</head>

			<body>
				<xsl:value-of select="//BBB[1]"/><br/>
				<xsl:value-of select="//BBB[2]"/><br/>
				<xsl:value-of select="//BBB[3]"/>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>