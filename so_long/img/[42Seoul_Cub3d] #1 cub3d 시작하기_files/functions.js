function open_img(url) {
	try {

		var left = Math.floor((screen.availWidth - 250) / 2);
		var top = Math.floor((screen.availHeight - 100) / 2);

		try { tatterImagePopup.close(); } catch(e) { }
		tatterImagePopup = window.open("", "", "width=250, height=100, left=" + left + ", top=" + top + ", scrollbars=no, resizable=yes");
		tatterImagePopup.document.open("text/html", "replace");
		tatterImagePopup.document.write(
			'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">\r\n' +
			'<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ko">\r\n' +
			'	<head>\r\n' +
			'		<meta http-equiv="content-type" content="text/html; charset=utf-8"/>\r\n' +
			'		<meta http-equiv="imagetoolbar" content="no" /> \r\n' +
			'		<title> :: View :: </title>\r\n' +
			'		<style type="text/css">\r\n' +
			'			html, body { width: 100%; height: 100%; margin: 0; padding: 0; cursor: pointer; text-align: center; line-height: 0; }\r\n' +
			'			div { width: 100%; height: 100%; overflow: auto; }\r\n' +
			'		</style>\r\n' +
			'		<script type="text/javascript">\r\n' +
			((navigator.userAgent.indexOf("Safari") > -1) ?
				'			function resizeImage() {\r\n' :
				'			window.onload = function() {\r\n') +
			'				var container = document.getElementById("Container");\r\n' +
			'				var image = document.getElementById("Image");\r\n' +
			'				var resizeWidth = 0, resizeHeight = 0, positionTop = 0, positionLeft = 0;\r\n' +
			'				var offsetTop = window.screenTop || window.screenY;\r\n' +
			'				var offsetLeft = window.screenLeft || window.screenX;\r\n' +
			'				if(navigator.userAgent.indexOf("Safari") > -1) {\r\n' +
			'					var width = Math.min(image.width + 50, screen.availWidth - 100);\r\n' +
			'					var height = Math.min(image.height + 50, screen.availHeight - 100);\r\n' +
			'					window.moveTo((screen.availWidth - width) / 2, (screen.availHeight - height) / 2);\r\n' +
			'					window.resizeTo(width, height);\r\n' +
			'					return;\r\n' +
			'				}\r\n' +
			'				if(container.scrollWidth > container.offsetWidth) {\r\n' +
			'					resizeWidth += container.scrollWidth - container.offsetWidth;\r\n' +
			'					if(container.offsetWidth + resizeWidth + 100 > screen.availWidth) {\r\n' +
			'						resizeWidth = screen.availWidth - container.offsetWidth - 100;\r\n' +
			'						positionLeft = -resizeWidth / 2;\r\n' +
			'						resizeHeight += 20;\r\n' +
			'					}\r\n' +
			'					else {\r\n' +
			'						positionLeft = -resizeWidth / 2;\r\n' +
			'					}\r\n' +
			'				}\r\n' +
			'				if(container.scrollHeight > container.offsetHeight) {\r\n' +
			'					resizeHeight += container.scrollHeight - container.offsetHeight;\r\n' +
			'					if(container.offsetHeight + resizeHeight + 100 > screen.availHeight - 50) {\r\n' +
			'						resizeHeight = screen.availHeight - container.offsetHeight - 100 - 40;\r\n' +
			'						positionTop = -resizeHeight / 2;\r\n' +
			'						resizeWidth += 20;\r\n' +
			'					}\r\n' +
			'					else {\r\n' +
			'						positionTop = -resizeHeight / 2;\r\n' +
			'					}\r\n' +
			'				}\r\n' +
			'				if(resizeWidth == 0 && resizeHeight == 0)\r\n' +
			'					image.style.marginTop = ((container.offsetHeight - image.height) / 2) + "px";\r\n' +
			'				window.moveBy(positionLeft, positionTop - 35);\r\n' +
			'				window.resizeBy(resizeWidth, resizeHeight);\r\n' +
			'			}\r\n' +
			'		</script>\r\n' +
			'	</head>\r\n' +
			'	<body>\r\n' +
			((navigator.userAgent.indexOf("Safari") > -1) ?
				'		<div id="Container"><img id="Image" src="' + url + '" alt="" onclick="window.close();" onload="resizeImage();"/></div>\r\n' :
				'		<div id="Container"><img id="Image" src="' + url + '" onclick="window.close();" alt=""/></div>\r\n') +
			'	<script type="text/javascript">	document.oncontextmenu = new Function (\'return false\'); ' +
			'		document.ondragstart = new Function (\'return false\'); ' +
			'		document.onselectstart = new Function (\'return false\'); </script>' +
			'	</body>\r\n' +
			'</html>'
		);
		tatterImagePopup.document.close();
		if(tatterImagePopup.document.focus)
			tatterImagePopup.document.focus();
	}
	catch(e) {
		window.open(url, "_blank");
	}
}