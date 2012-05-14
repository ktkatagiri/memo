// 座標オブジェクトのひな形
var Point = function() {
    // 引数が2個以上なら
    if (arguments.length >= 2) {
	this.x = arguments[0];
	this.y = arguments[1];
    } else {
	this.x = null;
	this.y = null;
    }
};

// 実際に線をp1からp2までの線を引く関数
var drawLine = function(ctx, p1, p2) {
    ctx.beginPath();
    ctx.moveTo(p1.x, p1.y);
    ctx.lineTo(p2.x, p2.y);
    ctx.stroke();
};

// マンデルブロ集合の描画
function drawMandelbrot(ctx){
    var a,b,x,y,zx,zy;
    var Xtable = new Array();
    // var loop = 100;
    var loop = 1000;
    var max = 500;
    var maxX = 500;
    var maxY = 1000;

    var med = max/2;
    var PosX = 0.0099;
    // var PosX = 0.01;
    var PosY = -1.40497;
    // var Zoom = 0.25;
    var Zoom = 0.000005;

    var colorMax = 0;

    for( var i=0 ; i<maxY ; i++ )
    {
        a = PosY + Zoom * ( (i-med) / max );
        Xtable[i] = new Array();
        for( var j=0 ; j<maxX ; j++ )
        {
            b = PosX + Zoom * ( (j-med) / max );
            x=0;y=0;
            for( var k=0 ; k<loop ; k++ )
            {
                zx = x*x-y*y+a;
                zy = 2*x*y+b;
                x = zx;
                y = zy;
                if( x*x+y*y>4 ) break;
            }
	    if(colorMax < k){ colorMax = k; }
            Xtable[i][j] = k;
        }
    }

    for(var i = 0; i < Xtable.length; i++) {
	for(var j = 0; j < Xtable[i].length; j++) {
	    ctx.beginPath();
	    ctx.fillStyle = 'rgb(' + parseInt(Xtable[i][j]/colorMax * 255,10) + ',' + parseInt(Xtable[i][j]/colorMax * 255, 10) + ',' + parseInt(Xtable[i][j]/colorMax * 255,10) + ')';
	    ctx.fillRect(i, j, 1, 1);
	    ctx.fill();
	    // ctx.stroke();
	}
    }
    
}

// バーニングシップフラクタルの描画
function drawBurningShip(ctx){
    var a,b,x,y,zx,zy;
    var Xtable = new Array();
    var loop = 500;
    var max = 500;

    var med = max/2;

    // ベスト？
    var PosX = -0.033;
    var PosY = - 1.755;
    var Zoom = 0.079;

    var colorMax = 0;

    for( var i=0 ; i<max ; i++ )
    {
        a = PosY + Zoom * ( (i-med) / max );
        Xtable[i] = new Array();
        for( var j=0 ; j<max ; j++)
        {
            b = PosX + Zoom * ( (j-med) / max );
            x=0;y=0;
            for( var k=0 ; k<loop ; k++ )
            {
		x = Math.abs(x);
		y = Math.abs(y);

                zx = x*x-y*y+a;
                zy = 2*x*y+b;
                x = zx;
                y = zy;
                if( x*x+y*y>4 ) break;
            }
	    if(colorMax < k){ colorMax = k; }
            Xtable[i][j] = k;
        }
    }

    for(var i = 0; i < Xtable.length; i++) {
	for(var j = 0; j < Xtable[i].length; j++) {
	    ctx.beginPath();
	    ctx.fillStyle = 'rgb(' + parseInt(255-Xtable[i][j]/colorMax * 255,10) + ',' + parseInt(255-Xtable[i][j]/colorMax * 255, 10) + ',' + parseInt(255-Xtable[i][j]/colorMax * 255,10) + ')';
	    ctx.fillRect(i, j, 1, 1);
	    ctx.fill();
	}
    }
    
}


// コッホ曲線の描画
// params, ctx: canvasの描画オブジェクト, p1: ポイント1, p2: ポイント2, n: 残りの再帰回数
var draw = function(ctx, p1, p2, n) {
    // ポイントオブジェクトを生成して，値をセット
    var p3 = new Point((2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3);
    var p4 = new Point((p1.x + 2 * p2.x) / 3, (p1.y + 2 * p2.y) / 3);

    // x,yは2点間の距離x,yでdisは直線距離
    var x = p2.x - p1.x;
    var y = - (p2.y - p1.y);
    var dis = Math.sqrt(x * x + y * y) / Math.sqrt(3);

    // 始点p
    var p5;
    var rad;
    var angle;

    // p1.x-p2.xが正か負かでp5の場所は変わる
    if (x >= 0) {
	// アークタンジェントとrad
        rad = Math.PI / 6;
	angle = Math.atan(y / x) + rad;
	p5 = new Point(p1.x + dis * Math.cos(angle),
		       p1.y - dis * Math.sin(angle));
    } else {
	// アークタンジェントとrad
        rad = - Math.PI / 6;
	angle = Math.atan(y / x) + rad;
	p5 = new Point(p2.x + dis * Math.cos(angle),
		       p2.y - dis * Math.sin(angle));
    }
    
    // 再帰上限なら線を引く
    if (n == 0) {
	drawLine(ctx, p1, p3);
	drawLine(ctx, p3, p5);
	drawLine(ctx, p5, p4);
	drawLine(ctx, p4, p2);
    } else {
	draw(ctx, p1, p3, n - 1);
	draw(ctx, p3, p5, n - 1);
	draw(ctx, p5, p4, n - 1);
	draw(ctx, p4, p2, n - 1);
    }
};

// ここからはじまる
var canvas_main = function(ctx) {
    // コッホ曲線
    // var p1 = {x: 10, y: 400};
    // var p2 = {x: 990, y: 400};
    // // // var p3 = {x: 250, y: 420};
    // draw(ctx, p1, p2, 2);
    // draw(ctx, p2, p3, 5);
    // draw(ctx, p3, p1, n);

    // マンデルブロ集合
    // drawMandelbrot(ctx);

    // バーニングシップフラクタル
    drawBurningShip(ctx);
};

