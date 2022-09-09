using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class PlayerScript : MonoBehaviour
{

    public float playerVelocity;
    public float boundary;
    private Vector3 playerPosition;
    private int playerLives;
    private int playerPoints;
    public AudioClip pointSound;
    public AudioClip lifeSound;    
    
    AudioSource audio_1;

    private int i = 0;
    private int levels=2;
    void Start()
    {

        playerPosition = gameObject.transform.position;
        playerLives = 6;
        playerPoints = 0;           
    }

    void addPoints(int points)
    {
        
            //суммирование очков
            playerPoints += points;
            audio_1 = GetComponent<AudioSource>();
            audio_1.PlayOneShot(pointSound);
        
    }

    void OnGUI() 
    {
        GUI.Label(new Rect(750.0f, 78.2f, 100.0f, 100.0f), "Live's:  " + playerLives + "    Score:  " + playerPoints);
    }
    

    void TakeLife()
    { 
        
        playerLives--;
        audio_1 = GetComponent<AudioSource>();
        audio_1.PlayOneShot(lifeSound);
    }

    
    void WinLose()
    {
                 // перезапускаем уровень
                    if (playerLives < 0)
                 {
                     SceneManager.LoadScene(i);

                   }
                     
                    if (((GameObject.FindGameObjectsWithTag("Block")).Length == 0) && (i < levels))
                     {
                            i++; 
                            SceneManager.LoadScene(i);                 

                    }
                    else
                    if ((GameObject.FindGameObjectsWithTag("Block")).Length == 0) 
                     {
                         Application.Quit();        

                    }
   
    
    
    }
    
    void Update()
    {                 

               if (Input.GetKeyDown(KeyCode.Escape)==true)
                {
                    Application.Quit();     
                }
         

                playerPosition.x += Input.GetAxis("Horizontal") * playerVelocity;
                transform.position = playerPosition;

                if (playerPosition.x < -boundary)
                {
                     transform.position = new Vector3(-boundary, playerPosition.y, playerPosition.z);
                }
                if (playerPosition.x > boundary)
                {
                 transform.position = new Vector3(boundary, playerPosition.y, playerPosition.z);
                }

         //проверка состояния игры     
            WinLose();
    }

   

   }


