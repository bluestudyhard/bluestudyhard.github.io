function edit() {
    document.querySelectorAll(".edit").forEach((item) =>  //DOM 这个函数可以获取class=".eidt"里面的所有元素
    {
        item.onclick = (e) => {//监听点击
            const par = e.target.parentElement.parentElement;//找到这个点击键前面的父元素,这里是父元素的父元素，也就是tr
            const uid = par.children[1].firstChild;
            [...par.children].forEach((ele, index) => {//对于里面的内容也就是子元素
                if ([0, par.children.length - 1].indexOf(index) === -1) {//遍历去掉td和</td> 所以是从0- -1
                    //indexOf() 方法可返回某个指定的字符串值在字符串中首次出现的位置。
                    //直接在里面打表单 innerHtml表示里面的文字
                    ele.innerHTML = `<input type="text" class="editable" value="${ele.innerHTML}" name="${ele.id}">`;
                }
            });
            par.lastElementChild.innerHTML =
                `<input type="submit" value="保存">` +
                `<input name="oldID" value="${uid.data}" style="display: none">`;
        }
    });
}