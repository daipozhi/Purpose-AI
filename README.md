# Purpose-AI
this project is Purpose AI , an open source project

How does computer process text,video,audio

(Purpose AI is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License;

 Purpose AI is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; )

(Feb 1st 2018 Updated)


    A, text , words

        download some random chinese text by a offline browser , have
        enough capacity ,more than 10GB ,in this version 
        only have a few .(english text may been processed in same
        way , need modify source code)

        get every sentence ,get every single chinese , and the after
         2 chinese and the after 3 chinese ...
        in this version , max number is 25 , store to memory ,
        if it is repeated , the count plus 1 .

        chinese word with 1 chinese ,its value is 5 .
        chinese word with 2 chinese  its value should more than chinese
            word with 1 chinese's value  plus chinese word with 1 chinese's 
            value , means >5+5 , in here it is 15 .
        chinese word with 3 chinese  its value should more than chinese
            word with 2 chinese's value  plus chinese word with 1 chinese's
            value , means >5+15 ,in here it is 25 .
        chinese word with 4 chinese  its value should more than chinese 
            word with 3 chinese's value  plus chinese word with 1 chinese's
            value , and more than chinese word with 2 chinese's value  plus
            chinese word with 2 chinese's value , means >25+5 and >15+15 , 
            in here it is 35 .
            (chinese word with 3 chinese's value  plus chinese word with 1 chinese's
            value , should same with chinese word with 2 chinese's value  plus
            chinese word with 2 chinese's value )
        chinese word with 5 chinese's value , for the same reason ,it is 45 .

        more accurate formula is :

        AI number:
          total value   formula 
         n1-- 5  ----   (starter) =5
         n2--15  ----   n1+n1+5   =15
         n3--25  ----   n2+n1+5   =25
         n4--35 ----    n3+n1+5   =35
         n5--45 ----    n4+n1+5   =45

        separate every sentence with any possible chinese words , if a 
            string is repeated , it is word ,  it has many possible 
            result ,every word has its value , at last , choose the 
            sentence which has highest value , sum every word's value ,
            choose the max value one .

        separate all text .

        so many text were separate to words , get all the words , it 
            is a word database .

        separate all text again , this time not by repeat , by word 
            database .

        all text were separate to words , get all the words,  we have 
            a new word database ,new word database is quite different 
            with old word database .

        after this step accuracy is about 80%

        make word courseware file,put frequently-used words into it,
            every word has its value , the value is same with automatic
            generated word ,chinese word with 1 chinese ,its value is 5,
            chinese word with 2 chinese  its value is 15 ... but its priority
            is higher ,separate every sentence by word courseware and automatic
            generated word base ,get all the words, it is 3rd word base .

        you may ask,we have word courseware ,why still need automatic generated
            word base ,in fact both are needed ,what computer can do let computer 
            do it ,what computer cannot do let human do it ,this is a rule ,
            otherwise ,it is incomplete.

        after this step accuracy is about 90%

        source code:

            Windows XP/Vista/7+MSYS+MINGW  or Ubuntu

            in MSYS ,you need open config.h file(in AI directory) set symbol AI_LINUX to 0 ,(#define AI_LINUX 0)
            in Ubuntu ,you need open config.h file(in AI directory) set symbol AI_LINUX to 1 ,(#define AI_LINUX 1)

            in MSYS , to build this project use build-msys.bat .
            in Ubuntu , to build this project use build-ubuntu.bat

            in 'work_dir'
                  'download' directory is text download by offline browser .
                  run a-step10-f3-msys.bat (list directory)(in Ubuntu run a-step10-f3-ubuntu.bat)
                  run program in  'webfind_b' (step20)(copy to 'work_dir')(get text , erase html mark)
                                (in this version, we kept 86 text file ,from stringbase000.txt to stringbase085.txt ,
                                 if you donnt want download by a offline browser , you can start at next step(step30))
                  run program in  'webfind39' (step30)(copy to 'work_dir', include 'cb.txt' )(erase punctuation)
                  run program in  'webfind4a' (step40)(copy to 'work_dir')(erase empty line , repeated line)
                  run program in  'webfind29e'(step50)(separate to words by repeate )
                  run program in  'webfind23c'(step60)(get all words ,generate word database)
                  run program in  'webfind24b'(step70)(separate to words by word database )
                  run program in  'webfind25c'(step80)(get all words ,generate word database again )

                  run program in  'webfind53'(step90)(separate to words by word courseware and word database )
				(word courseware is in file words-cw01.txt and words-cw02_sort.txt , how to make 
				word courseware please read readme.txt file in directory webfind50 )
                  run program in  'webfind54'(step100)(get all words ,generate 3rd word database )

                  (in here , chinese is coded in GB18030 ,in Windows, you can directly open it , if you are in Ubuntu,
                   you need convert chinese to utf8 , you can run program in directory 'tools-3',
                   ./gb18030-to-utf8.exe myfile.txt ,it will convert chinese to utf8 and copy to myfile.utf8.txt ,
                   if you modified a text file in Ubuntu , and want to commit to the program , you can run
                   program in directory 'tools-4' , ./utf8-to-gb18030.exe myfile.utf8.txt , it will convert chinese
                   to GB18030 and copy to myfile.txt .) 

			(Mar 21th 2014 version added support to repeat times of words, and better algorithm )
			(DEC 21th 2015 version changed AI Number,updated document,added tools)
			(Feb  1st 2018 version added word courseware )


    B text ,grammer(phrase)

        save all the permutation and combination of words to memory , 
            total load 3 files everytime , 000-002 ,or 003-005 , repeated is
            grammer(phrase) , every grammer(phrase) has its value ,
            as AI number .

        make grammer courseware ,tell computer how to describe many concepts ,
	    include 'date' 'time' 'temperature' 'percent'... ,every grammer
	    has its value ,its priority is higher than automatic generated
	    grammer .

        separate sentence by word courseware and word database , not only 
	    keep the highest value one , also keep some lower value ones ,
	    (highest one separate sentence by a word with 3 chinese, lower 
	    ones may separate sentence by a word with 2 chinese or a word with
            1 chiness .) so there are many result , shorter sentence 
            have 30 result ,longer sentence may have 200 result , choose 
	    the 20 highest value ones , calculate its grammer value , add with
	    its word value ,the highest value one is result.

        separate all text . 

        get all words , it is 4th word base .

        get all grammer , it is grammer base .

        after this step accuracy is about 91%

        source code:

            Windows XP/7+MSYS+MINGW  or Ubuntu

            grammer courseware is in file grammer-cw03.txt

                run program in webfind61 (step210)(copy to work_dir)
                    (separate sentence by word courseware and word database , 
		    not only keep the highest value one , also keep some lower 
                    value ones , calculate its grammer value , add with its word value ,
		    choose max value one )

                run program in webfind62 (step220)(copy to work_dir)
		    ( get all the words , it is 4th word base )

                run program in webwind63 (step230)(copy to work_dir)
		    ( get all the grammer , it is grammer base )

			(Mar 21th 2014 version added support to repeat times of grammers, repeat times of words, and better algorithm )
			(Feb  1st 2018 version added grammer courseware )




    C,video

         * video recognition need super computer , need high performance

         * need video database

         * may add one pixel's value by some simple condition ,physically 
               close ,similar color ,move to same direction , texture 
               similar , by those condition separate one picture to small,
               different color pieces .

         * those pieces may have many combination,select some combination 
               of similar physical location, or select some combination of 
	       relatively independent movement.

	 * some combination maybe 'material scense' (you can see it in after ) , 
               in photogragh , some combination maybe not , in most painting .

         * add more conditions ,different brightness , other objects of the
               block ,zoom , 3D rotation ,different proportion .

         * compare with all objects in video database , the highest value one 
               is result .

         * build video database can use computer process 1000 movies or 3000
              TV programs , in different video clips, search for same 
              characteristics objects(a combination of color pieces in this 
              video clips and a combination of color pieces in that video 
              clips have similar shape or have similar characteristics), 
	      repeated is a object , all those object means a video database , 
              processe 1000 movies again (this time by video database),and 
              get objects again ,it is a new video database , I estimate this 
              is construction procedure .
     
         * many objects's combination is a scenes , this is sandy beach ,this 
              is forest ,this is kitchen , this is office, if computer can 
              recognize these scenes , it is helpful for computer to recognize
              objects .

         * knowledge , a man in 1000 years ago , look at today's flat TV , he 
	      don't know what it is ,look at today's iPhone , he don't know what
	      it is , robot need human society's general knowledge .

	 * how to get knowledge , a procedure divided into several parts ,for example ,
	      a man have dinner ,he walk to chair ,sit down, pick up knife and fork ,
	      start to eat , every part have many features ,combine these parts 
	      together , also have many features ,get the features we need ,this is how to
	      get knowledge .

	 * summary,induce,generalization , a object has unlimited features , but after
	      summary,induce,generalization , it is broadly combined with a few features ,
	      a few color . a few material scense , a few geometry . a few parts , size .

    D,audio

        * need audio database ,store sound objects .

        * build audio database can rely computer process 1000 movies or 
              3000 TV programs .

        * audio is wave , is different freq , similiar freq ,or similiar 
              volume, or same time happend audio may add value .


    E,abstract conception

	* a famous song :"Bridge Over Troubled Water" , in the song ,"Bridge" is a 
	      abstract conception ,"Troubled Water" is also a abstract conception ,
	      you can't see it , you can't touch it ,a object in real world to describe 
	      a abstract conception ,to understand this concept need life experience . 





    * 3d movies

         at begining,compuer don't have video database,so we need 3d movie,like 
         human have 2 eyes,and like every animal with eyes ,we don't have 
         many 3d movies, and it is not fully 3d, it is 2.5d or 2.75d ,if 
         it is not good enough,we need 3d camera to record many 3d video .



    * material scense

         every surface has it's material sense

         color ,grain ,stripe ,smoothness,roughness,particle size ,reflective,
         transparency ,Stereoscopic 3D surface texture ,repeated feature,is a 
         concept , a material sense ,including metal wood plastic cloth paper glass water



    * courseware for computer

         we need many courseware for computer,like a mother teach her kids, 
         this is what and that is what .





