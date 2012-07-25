# Desc: Device definitions for Activemedia robots.
# Author: Richard Vaughan, Andrew Howard,  Luis Riazuelo
# Date: 10 Jun 2002
# CVS: $Id: pioneer.inc,v 1.30 2008-01-15 01:25:42 rtv Exp $

# The Pioneer2DX sonar array

#  prototype for p2dx sonar sensors
define ir sensor
(
  # define the size of each transducer [xsize ysize zsize] in meters
  size [0.01 0.05 0.01 ] 
  # define the range bounds [min max]
  range [0 5.0]
  # define the angular field of view in degrees
  fov 60
  # define the number of samples spread over the fov
  samples 1
)

define ir_high sensor
(
  # define the size of each transducer [xsize ysize zsize] in meters
  size [0.01 0.05 0.01 ] 
  # define the range bounds [min max]
  range [0 10]
  # define the angular field of view in degrees
  fov 60
  # define the number of samples spread over the fov
  samples 1
)


define alice_sonar_front ranger
(
 # 3 transducers spread about the robot as follows
  ir( pose [ 0.5 0 -0.8 60 ] )
  ir( pose [ 0.5 0 -0.8 0 ] )
  ir( pose [ 0.5 0 -0.8 -60 ] )

)

define alice_sonar_high ranger
(
  ir_high( pose [ 0.5 0 0 0 ] )
)


define alice_base position 
(
  color "red"			# Default color.
  drive "diff"		 	# Differential steering model.
  gui_nose 1                  	# Draw a nose on the robot so we can see which way it points
  obstacle_return 1           	# Can hit things.
  ranger_return 1           	# reflects sonar beams

  localization "gps"         	  
  localization_origin [0 0 0 0] 	# Start odometry at (0, 0, 0).

  # four DOF kinematics limits
  # [ xmin xmax ymin ymax zmin zmax amin amax ]				
  velocity_bounds [-0.5 0.5 0 0 0 0 -90.0 90.0 ]					
  acceleration_bounds [-0.5 0.5 0 0 0 0 -90 90.0 ]
)



define alice2d_base_no_sonar alice_base
(
  # actual size
  #size [0.44 0.38 0.22] # sizes from MobileRobots' web site

  # the pioneer's center of rotation is offset from its center of area
  #origin [-0.04 0 0 0]

  # draw a nose on the robot so we can see which way it points
  gui_nose 1

  # estimated mass in KG
  mass 0.3 
  # differential steering model
  #drive "diff"
 )



define alice2d_base_front_sonar alice2d_base_no_sonar
(
  # use the sonar array defined above with a small vertical offset to
  # drop the sensors into the robot body
#  alice_sonar_front( pose [0 0 -0.03 0] )
  alice_sonar_front()
  alice_sonar_high() 
)


define alice2d alice2d_base_front_sonar
(  
  # simplified Body shape:
  block( 
    points 4
    point[0] [0.5 0.5]
    point[1] [0.5 -0.5]
    point[2] [-0.5 -0.5]
    point[3] [-0.5 0.5 ]
    z [0 0.5]
  )
)





