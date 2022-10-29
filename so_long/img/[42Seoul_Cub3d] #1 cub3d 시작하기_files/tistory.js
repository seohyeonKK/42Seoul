(function ($) {
  $(document).ready(function () {
    renderLightBox();
  });

  function getOriginalImageUrl(url) {
    if (url.match(/^https?:\/\/\S+\.daumcdn\.net\/cfile\/\S+\/\S+/)) {
      return url + '?original'
    }

    // https://t1.daumcdn.net/blogfile/fs3/29_blog_2007_07_22_00_33_46a227604b578?x-content-disposition=inline
    if (url.match(/^https?:\/\/\S+\.daumcdn\.net\/(blogfile|planet)\/\S+\/\S+/)) {
      return url.split("?")[0] + '?original'
    }

    return url
  }

  function renderLightBox() {
    if (typeof lightbox !== 'undefined') {
      lightbox.option({
        stopEvent: true,
      });
    }

    $('img.txc-image, img.tx-daum-image').each(function (index, element) {
      // parent 가 'a', 즉 링크가 걸린 이미지일 경우 lightbox를 넣으면 안되므로
      // 체크해서 스킵한다.
      // 단, href="javascripｔ:realImgView"인 경우 스킵하지 않는다. (= lightbox 보여줘야함)
      if (element.parentElement && element.parentElement.tagName.toLowerCase() === 'a') {
        var href = $(element.parentElement).attr("href");
        if (href && href.indexOf("javascripｔ:realImgView") > -1) {
          element.parentElement.setAttribute('href', getOriginalImageUrl(element.getAttribute('src')));
          element.parentElement.setAttribute('data-lightbox', 'lightbox');
          element.parentElement.setAttribute('data-alt', element.getAttribute('data-filename'));
        }

        return;
      }

      $(element).wrap('<a href="'+ getOriginalImageUrl(element.getAttribute('src')) +'" data-lightbox="lightbox" data-alt="' + element.getAttribute('data-filename') + '"></a>');
    });
  }
})(tjQuery);
