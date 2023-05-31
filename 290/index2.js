var empty_arr = [];
   function clear_text(){
       var get_input = document.getElementsByClassName('advice-input-element');
       for(var i =0; i < get_input.length; i++){
            var each_text = get_input[i].querySelector('input, textarea');
            each_text.value = '';
       }


   }

   function show_modal(){
    var modal_backdrop = document.getElementById('modal-backdrop');
    var twit_modal  = document.getElementById('create-advice-modal');
    modal_backdrop.classList.remove('hidden');
    twit_modal.classList.remove('hidden');
    }

    function hide_model(){
        var modal_backdrop = document.getElementById('modal-backdrop');
        var twit_modal  = document.getElementById('create-advice-modal');
        modal_backdrop.classList.add('hidden');
        twit_modal.classList.add('hidden');
        clear_text();
    }

    function other_modal(){
        var modal_backdrop = document.getElementById('modal-backdrop');
        var twit_modal  = document.getElementById('create-picture-modal');
        modal_backdrop.classList.remove('hidden');
        twit_modal.classList.remove('hidden');

    }
    function hide_other_model(){
        var modal_backdrop = document.getElementById('modal-backdrop');
        var twit_modal  = document.getElementById('create-picture-modal');
        modal_backdrop.classList.add('hidden');
        twit_modal.classList.add('hidden');
        clear_text();
    }
 /*******************************************************************
 * This section is to click the button that adds advice
 *******************************************************************/
   var create_button = document.getElementById("create-twit-button");
   create_button.addEventListener('click', function (){
       show_modal();
    });

   var cancel_button = document.querySelector(".modal-cancel-button");
   if(cancel_button){
       cancel_button.addEventListener('click', function(){
       hide_model();
       });
    }

    var x_button = document.querySelector(".modal-close-button");
    x_button.addEventListener('click', function(){
        hide_model();
    })


/********************************************************************
 * This sectionid for the reaction buttons like
 ********************************************************************/
    var container = document.getElementsByClassName("advice-container")[0];

        container.addEventListener('click', function(event){
          var el = event.target;
            console.log(el);
            if(el.classList.contains("fa-heart")){
                el = el.parentNode;
            }
            if(el.classList.contains("create-like-button")){
                el.classList.add('liked')
            }

        })
/**********************************************
*This section is to input the comment
***********************************************/
var i_container = document.getElementsByClassName("advice-container")[0];

        i_container.addEventListener('click', function(event){
          var ele = event.target;
            console.log(ele);
            if(ele.classList.contains("fa-comment")){
                ele = ele.parentNode;
            }
            if(ele.classList.contains("create-comment-button")){
                ele.classList.add('comment')
                show_modal();
            }

        })
/********************************************************************
 * This sectionid for the reaction buttons Image
 ********************************************************************/
   /* var l_container = document.getElementsByClassName("advice-container")[0];

    container.addEventListener('click', function(event){
      var elem = event.target;
        console.log(elem);
        if(elem.classList.contains("fa-image")){
            elem= elem.parentNode;
        }
        if(elem.classList.contains("create-image-button")){
            elem.classList.add('image')
            other_modal();
        }

    })*/





  /**********************************************************************************
 * This function creates a new twit box with the values that the user entered. It is
 *   formatted to fit with the other boxes.
 *********************************************************************/
var adviceSearch = document.getElementById("navbar-search-input");
var adviceSearchButton = document.getElementById("navbar-search-button")
var adviceAuthor = document.getElementById("advice-attribution-input");
var advice_text = document.getElementById("advice-text-input");
var button = document.getElementById("advice-twit-button");
/*var likeButton = document.getElementsByClassName(create-like-button);
var commentButton = document.getElementsByClassName(create-comment-button);
var imageButton = document.getElementsByClassName(create-image-button);*/
var modal = document.getElementById("create-twit-modal");
var modalBackdrop = document.getElementById("modal-backdrop");
var modalAcceptButton = document.getElementsByClassName("modal-accept-button")[0];
var modalCloseButton = document.getElementsByClassName("modal-close-button")[0];
var modalCancelButton  = document.getElementsByClassName("modal-cancel-button")[0];

function modalToggle(event) {
    if (modal.classList.contains("hidden")) {
      advice_text.value = "";
      adviceAuthor.value = "";
      modal.classList.remove('hidden');
      modalBackdrop.classList.remove('hidden');
    } else {
      modal.classList.add('hidden');
      modalBackdrop.classList.add('hidden');
    }
  }

/*function addAdvice(event) {
    if ((advice_text.value == "") || (adviceAuthor.value == "")) {
      alert("You have not entered a value for either text or author")
      return;
    }

    var icon = document.createElement('i');
    icon.classList.add('fa');
    icon.classList.add('fa-camera');

    var adviceIcon = document.createElement('div');
    adviceIcon.classList.add('advice-icon');
    adviceIcon.appendChild(icon);

    var text = document.createElement('p');
    text.classList.add('advice_text');
    text.textContent = advice_text.value;

    var author = document.createElement('a');
    author.href = '#';
    author.textContent = adviceAuthor.value;

    var attribution = document.createElement('p');
    attribution.classList.add('advice-attribution-input');
    attribution.appendChild(author);

    var adviceContent = document.createElement('div');
    adviceContent.classList.add("advice-content");
    adviceContent.appendChild(text);
    adviceContent.appendChild(attribution);

    var advice = document.createElement('article');
    advice.classList.add('advice');
    advice.appendChild(adviceIcon);
    advice.appendChild(adviceContent);

    var body = document.getElementsByClassName('advice-container')[0];
    body.appendChild(advice);

    modalToggle();
  }

  adviceSearch.addEventListener('keyup', search);
  adviceSearchButton.addEventListener('click', search);
  button.addEventListener('click', modalToggle);
  modalAcceptButton.addEventListener('click', addAdvice);
  modalCloseButton.addEventListener('click', modalToggle);
  modalCancelButton.addEventListener('click', modalToggle);


    var create_twit = document.querySelector(".modal-accept-button");

     if(create_twit){
         create_twit.addEventListener('click', function(){
             var input = document.getElementById("advice-text-input").value;
             var writer = document.getElementById("advice-attribution-input").value;
         if (input && writer){
              empty_arr.push({text: input, author: writer});
             for(var c=0; c<empty_arr.length; c++){
                 insert_twit(empty_arr[c].text, empty_arr[c].author);
             }
             hide_model();
         }
         else{
             alert("Incomplete input");
         }
    });
 }*/

/*************************************************************************
 * Image Container
 *************************************************************************/
 function createPhotoCard(photoURL, caption) {

    /*var photoCardContext = {
      url: photoURL,
      caption: caption
    };

    var photoCardHtml = Handlebars.templates.photoCard(photoCardContext);
    console.log("== photoCardHtml:", photoCardHtml);

    return photoCardHtml;*/

     var photoCardSection = document.createElement('section');
     photoCardSection.classList.add('photo-card');

     var imgContainerDiv = document.createElement('div');
     imgContainerDiv.classList.add('img-container');
     photoCardSection.appendChild(imgContainerDiv);

     var img = document.createElement('img');
     img.classList.add('person-photo-img');
     img.src = photoURL;
     imgContainerDiv.appendChild(img);

     var captionDiv = document.createElement('div');
     captionDiv.classList.add('caption');
     captionDiv.textContent = caption;
     photoCardSection.appendChild(captionDiv);

     return photoCardSection;

  }


  function handleModalAcceptClick() {

    var photoURL = document.getElementById('photo-url-input').value.trim();
    var caption = document.getElementById('photo-caption-input').value.trim();

    if (!photoURL || !caption) {
      alert("You must fill in all of the fields!");
    } else {

      var newPhotoCard = createPhotoCard(photoURL, caption);
      var photoCardContainer = document.querySelector('.photo-card-container');

       photoCardContainer.appendChild(newPhotoCard);
     // photoCardContainer.insertAdjacentHTML('beforeend', newPhotoCard);

      hideModal();

    }

  }


  function showModal() {

    var modal = document.getElementById('create-picture-modal');
    var modalBackdrop = document.getElementById('modal-backdrop');

    modal.classList.remove('hidden');
    modalBackdrop.classList.remove('hidden');

  }


  function clearModalInputs() {

    var modalInputElements = document.querySelectorAll('#create-photo-modal input')
    for (var i = 0; i < modalInputElements.length; i++) {
      modalInputElements[i].value = '';
    }

  }


  function hideModal() {

    var modal = document.getElementById('create-picture-modal');
    var modalBackdrop = document.getElementById('modal-backdrop');

    modal.classList.add('hidden');
    modalBackdrop.classList.add('hidden');

    clearModalInputs();

  }


  /*
   * Wait until the DOM content is loaded, and then hook up UI interactions, etc.
   */
  window.addEventListener('DOMContentLoaded', function () {


    var addPhotoButton = document.getElementsByClassName('advice-container')[0];
    //addPhotoButton.addEventListener('click', showModal);

    addPhotoButton.addEventListener('click', function(event){
        console.log("Dom content is loaded");
        var elem = event.target;
          console.log(elem);
          if(elem.classList.contains("fa-image")){
              elem= elem.parentNode;
          }

          if(elem.classList.contains("create-image-button")){
              elem.classList.add('image')
              showModal();
          }
        });
    var modalAcceptButton = document.getElementsByClassName('modal-accept-button')[0];
    modalAcceptButton.addEventListener('click', handleModalAcceptClick);

    var modalHideButtons = document.getElementsByClassName('modal-hide-button');
    for (var i = 0; i < modalHideButtons.length; i++) {
      modalHideButtons[i].addEventListener('click', hideModal);
    }

    });


    /*var modalAcceptButton = document.getElementById('modal-accept');
    modalAcceptButton.addEventListener('click', handleModalAcceptClick);

    var modalHideButtons = document.getElementsByClassName('modal-hide-button');
    for (var i = 0; i < modalHideButtons.length; i++) {
      modalHideButtons[i].addEventListener('click', hideModal);
    }*/
