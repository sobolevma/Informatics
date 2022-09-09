
using UnityEngine;
using System.Collections;

public class BallScript : MonoBehaviour
{

    private bool ballIsActive;
    private Vector3 ballPosition;
    private Vector2 ballInitialForce;
    private Rigidbody2D ballRigidBody;
    // GameObject
    public GameObject playerObject;
    public AudioClip hitSound;
    //public static SoundTrack PlaySound(AudioClip clip, float volume=1,float pitch=1,float loopTime=0, float delayTime=0);
    AudioSource audio1;
   
    void Start()
    {
       
        // создаем силу
        ballInitialForce = new Vector2(100.0f, 300.0f);
        GetComponent<Rigidbody2D>().velocity = Vector2.zero;

        ballRigidBody = GetComponent<Rigidbody2D>();
        // переводим в неактивное состояние
        ballIsActive = false;

        // запоминаем положение
        ballPosition = transform.position;
        ballPosition.y = -5.0f;

        
    }

    
    
    
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (ballIsActive)
        {
            audio1 = GetComponent<AudioSource>();
            audio1.PlayOneShot(hitSound);
            
        }
    }


    
    
    void Update()
    {

        
        // проверка нажатия на пробел
        if (Input.GetButtonDown("Jump") == true)
        {
            // проверка состояния
            if (!ballIsActive)
            {
                // сброс всех сил
                ballRigidBody.isKinematic = false;
                          
                
                // применим силу
                ballRigidBody.AddForce(ballInitialForce);
                // зададим активное состояние
                ballIsActive = !ballIsActive;
            }

            if (!ballIsActive && playerObject != null)
            {
                // задаем новую позицию шарика
                ballPosition.x = playerObject.transform.position.x;

                // устанавливаем позицию шара
                transform.position = ballPosition;
            }

            // проверка падения шара
            if (ballIsActive && transform.position.y < -6)
            {
                ballIsActive = !ballIsActive;
                ballPosition.x = playerObject.transform.position.x;
               
                transform.position = ballPosition;
                GetComponent<Rigidbody2D>().isKinematic = false;
                GetComponent<Rigidbody2D>().velocity = Vector2.zero;

                ballRigidBody.isKinematic = true;

                //добавим вызов метода
                playerObject.SendMessage("TakeLife");
            }
        }
    }
}
