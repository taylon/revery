open Ctypes;

module SkiaTypes = SkiaWrappedTypes.M(Skia_generated_type_stubs);

module M = (F: FOREIGN) => {
  // module Ctypes_for_stubs = {
  //   include Ctypes;

  //   let (@->) = F.(@->);
  //   let returning = F.returning;
  //   let foreign = F.foreign;
  // };
  // open Ctypes_for_stubs;
  open F;

  type colorType = SkiaTypes.colorType;
  let colorType = SkiaTypes.colorType;
  type alphaType = SkiaTypes.alphaType;
  let alphaType = SkiaTypes.alphaType;

  module Color = {
    type t = Unsigned.uint32;
    let t = uint32_t;
  };

  module FontStyle = {
    type t = ptr(structure(SkiaTypes.FontStyle.t));
    let t = ptr(SkiaTypes.FontStyle.t);

    type slant = SkiaTypes.FontStyle.slant;
    let slant = SkiaTypes.FontStyle.slant;

    let make =
      foreign("sk_fontstyle_new", int @-> int @-> slant @-> returning(t));
  };

  module TextEncoding = {
    type t = SkiaTypes.TextEncoding.t;
    let t = SkiaTypes.TextEncoding.t;
  };

  module Hinting = {
    type t = SkiaTypes.Hinting.t;
    let t = SkiaTypes.Hinting.t;
  };

  module Typeface = {
    type t = ptr(structure(SkiaTypes.Typeface.t));
    let t = ptr(SkiaTypes.Typeface.t);

    let makeFromName =
      foreign(
        "sk_typeface_create_from_name_with_font_style",
        string @-> FontStyle.t @-> returning(ptr_opt(SkiaTypes.Typeface.t)),
      );

    let makeFromFile =
      foreign(
        "sk_typeface_create_from_file",
        string @-> int @-> returning(ptr_opt(SkiaTypes.Typeface.t)),
      );
  };

  module FontMetrics = {
    type t = ptr(structure(SkiaTypes.FontMetrics.t));
    let t = ptr(SkiaTypes.FontMetrics.t);

    let make = () => allocate_n(~count=1, SkiaTypes.FontMetrics.t);

    let getAscent = metrics => getf(!@metrics, SkiaTypes.FontMetrics.ascent);
    let getDescent = metrics =>
      getf(!@metrics, SkiaTypes.FontMetrics.descent);
    let getTop = metrics => getf(!@metrics, SkiaTypes.FontMetrics.top);
    let getBottom = metrics => getf(!@metrics, SkiaTypes.FontMetrics.bottom);
    let getUnderlineThickness = metrics =>
      getf(!@metrics, SkiaTypes.FontMetrics.underlineThickness);
    let getUnderlinePosition = metrics =>
      getf(!@metrics, SkiaTypes.FontMetrics.underlinePosition);
  };

  module ImageFilter = {
    type t = ptr(structure(SkiaTypes.ImageFilter.t));
    let t = ptr(SkiaTypes.ImageFilter.t);

    module CropRect = {
      type t = ptr(structure(SkiaTypes.ImageFilter.CropRect.t));
      let t = ptr(SkiaTypes.ImageFilter.CropRect.t);
    };

    let delete = foreign("sk_imagefilter_unref", t @-> returning(void));

    module DropShadow = {
      type shadowMode = SkiaTypes.ImageFilter.DropShadow.shadowMode;
      let shadowMode = SkiaTypes.ImageFilter.DropShadow.shadowMode;

      let allocate =
        foreign(
          "sk_imagefilter_new_drop_shadow",
          float
          @-> float
          @-> float
          @-> float
          @-> Color.t
          @-> shadowMode
          @-> ptr_opt(SkiaTypes.ImageFilter.t)
          @-> ptr_opt(SkiaTypes.ImageFilter.CropRect.t)
          @-> returning(t),
        );
    };
  };

  module Paint = {
    type t = ptr(structure(SkiaTypes.Paint.t));
    let t = ptr(SkiaTypes.Paint.t);
    type style = SkiaTypes.Paint.style;
    let style = SkiaTypes.Paint.style;

    let allocate = foreign("sk_paint_new", void @-> returning(t));
    let delete = foreign("sk_paint_delete", t @-> returning(void));

    let setColor =
      foreign("sk_paint_set_color", t @-> Color.t @-> returning(void));
    let setAntiAlias =
      foreign("sk_paint_set_antialias", t @-> bool @-> returning(void));
    let setStyle =
      foreign("sk_paint_set_style", t @-> style @-> returning(void));
    let setStrokeWidth =
      foreign("sk_paint_set_stroke_width", t @-> float @-> returning(void));

    let setTypeface =
      foreign("sk_paint_set_typeface", t @-> Typeface.t @-> returning(void));

    let setLcdRenderText =
      foreign(
        "sk_paint_set_lcd_render_text",
        t @-> bool @-> returning(void),
      );

    let setSubpixelText =
      foreign("sk_paint_set_subpixel_text", t @-> bool @-> returning(void));

    let setTextSize =
      foreign("sk_paint_set_textsize", t @-> float @-> returning(void));

    let getFontMetrics =
      foreign(
        "sk_paint_get_fontmetrics",
        t @-> ptr(SkiaTypes.FontMetrics.t) @-> float @-> returning(float),
      );

    let isAutohinted =
      foreign("sk_paint_is_autohinted", t @-> returning(bool));

    let setAutohinted =
      foreign("sk_paint_set_autohinted", t @-> bool @-> returning(void));

    let isAutohinted =
      foreign("sk_paint_is_autohinted", t @-> returning(bool));

    let getHinting =
      foreign("sk_paint_get_hinting", t @-> returning(Hinting.t));

    let setHinting =
      foreign("sk_paint_set_hinting", t @-> Hinting.t @-> returning(void));

    let measureText =
      foreign(
        "sk_paint_measure_text",
        t
        @-> string
        @-> int
        @-> ptr_opt(SkiaTypes.Rect.t)
        @-> returning(float),
      );

    let setImageFilter =
      foreign(
        "sk_paint_set_imagefilter",
        t @-> ImageFilter.t @-> returning(void),
      );

    let getTextEncoding =
      foreign("sk_paint_get_text_encoding", t @-> returning(TextEncoding.t));

    let setTextEncoding =
      foreign(
        "sk_paint_set_text_encoding",
        t @-> TextEncoding.t @-> returning(void),
      );
  };

  module Point = {
    type t = ptr(structure(SkiaTypes.Point.t));
    let t = ptr(SkiaTypes.Point.t);

    let make = (x, y) => {
      let point = allocate_n(SkiaTypes.Point.t, ~count=1);
      setf(!@point, SkiaTypes.Point.x, x);
      setf(!@point, SkiaTypes.Point.y, y);
      point;
    };

    let getX = point => {
      getf(!@point, SkiaTypes.Point.x);
    };
    let getY = point => {
      getf(!@point, SkiaTypes.Point.y);
    };
  };

  module Vector = {
    type t = ptr(structure(SkiaTypes.Vector.t));
    let t = ptr(SkiaTypes.Vector.t);

    let make = (x, y) => {
      let point = allocate_n(SkiaTypes.Vector.t, ~count=1);
      setf(!@point, SkiaTypes.Vector.x, x);
      setf(!@point, SkiaTypes.Vector.y, y);
      point;
    };

    let getX = point => {
      getf(!@point, SkiaTypes.Vector.x);
    };
    let getY = point => {
      getf(!@point, SkiaTypes.Vector.y);
    };
  };

  module IRect = {
    type t = ptr(structure(SkiaTypes.IRect.t));
    let t = ptr(SkiaTypes.IRect.t);

    let makeEmpty = () => {
      let iRect = allocate_n(SkiaTypes.IRect.t, ~count=1);
      setf(!@iRect, SkiaTypes.IRect.left, Int32.of_int(0));
      setf(!@iRect, SkiaTypes.IRect.top, Int32.of_int(0));
      setf(!@iRect, SkiaTypes.IRect.right, Int32.of_int(0));
      setf(!@iRect, SkiaTypes.IRect.bottom, Int32.of_int(0));
      iRect;
    };
    let makeLtrb = (left, top, right, bottom) => {
      let iRect = allocate_n(SkiaTypes.IRect.t, ~count=1);
      setf(!@iRect, SkiaTypes.IRect.left, left);
      setf(!@iRect, SkiaTypes.IRect.top, top);
      setf(!@iRect, SkiaTypes.IRect.right, right);
      setf(!@iRect, SkiaTypes.IRect.bottom, bottom);
      iRect;
    };
  };

  module Rect = {
    type t = ptr(structure(SkiaTypes.Rect.t));
    let t = ptr(SkiaTypes.Rect.t);

    let makeEmpty = () => {
      let rect = allocate_n(SkiaTypes.Rect.t, ~count=1);
      setf(!@rect, SkiaTypes.Rect.left, 0.);
      setf(!@rect, SkiaTypes.Rect.top, 0.);
      setf(!@rect, SkiaTypes.Rect.right, 0.);
      setf(!@rect, SkiaTypes.Rect.bottom, 0.);
      rect;
    };
    let makeLtrb = (left, top, right, bottom) => {
      let rect = allocate_n(SkiaTypes.Rect.t, ~count=1);
      setf(!@rect, SkiaTypes.Rect.left, left);
      setf(!@rect, SkiaTypes.Rect.top, top);
      setf(!@rect, SkiaTypes.Rect.right, right);
      setf(!@rect, SkiaTypes.Rect.bottom, bottom);
      rect;
    };
    let getLeft = rect => {
      getf(!@rect, SkiaTypes.Rect.left);
    };
    let getTop = rect => {
      getf(!@rect, SkiaTypes.Rect.top);
    };
    let getRight = rect => {
      getf(!@rect, SkiaTypes.Rect.right);
    };
    let getBottom = rect => {
      getf(!@rect, SkiaTypes.Rect.bottom);
    };
  };

  module Matrix = {
    type t = ptr(structure(SkiaTypes.Matrix.t));
    let t = ptr(SkiaTypes.Matrix.t);

    let make = () => allocate_n(SkiaTypes.Matrix.t, ~count=1);

    let setAll =
        (
          matrix,
          scaleX,
          skewX,
          translateX,
          skewY,
          scaleY,
          translateY,
          perspective0,
          perspective1,
          perspective2,
        ) => {
      let mat = getf(!@matrix, SkiaTypes.Matrix.mat);
      CArray.set(mat, 0, scaleX);
      CArray.set(mat, 1, skewX);
      CArray.set(mat, 2, translateX);
      CArray.set(mat, 3, skewY);
      CArray.set(mat, 4, scaleY);
      CArray.set(mat, 5, translateY);
      CArray.set(mat, 6, perspective0);
      CArray.set(mat, 7, perspective1);
      CArray.set(mat, 8, perspective2);
    };
    let get = (matrix, index) => {
      let mat = getf(!@matrix, SkiaTypes.Matrix.mat);
      CArray.get(mat, index);
    };

    let set = (matrix, index, value) => {
      let mat = getf(!@matrix, SkiaTypes.Matrix.mat);
      CArray.set(mat, index, value);
    };

    let invert =
      foreign("sk_matrix_try_invert", t @-> t @-> returning(bool));
    let concat =
      foreign("sk_matrix_concat", t @-> t @-> t @-> returning(void));
    let preConcat =
      foreign("sk_matrix_pre_concat", t @-> t @-> returning(void));
    let postConcat =
      foreign("sk_matrix_post_concat", t @-> t @-> returning(void));
    let mapRect =
      foreign(
        "sk_matrix_map_rect",
        t @-> Rect.t @-> Rect.t @-> returning(void),
      );
    let mapPoints =
      foreign(
        "sk_matrix_map_points",
        t @-> Point.t @-> Point.t @-> int @-> returning(void),
      );
    let mapVectors =
      foreign(
        "sk_matrix_map_vectors",
        t @-> Vector.t @-> Vector.t @-> int @-> returning(void),
      );
    let mapXy =
      foreign(
        "sk_matrix_map_xy",
        t @-> float @-> float @-> Point.t @-> returning(void),
      );
    let mapVector =
      foreign(
        "sk_matrix_map_vector",
        t @-> float @-> float @-> Vector.t @-> returning(void),
      );
    let mapRadius =
      foreign("sk_matrix_map_radius", t @-> float @-> returning(float));
  };

  module Matrix44 = {
    type t = ptr(structure(SkiaTypes.Matrix44.t));
    let t = ptr(SkiaTypes.Matrix44.t);

    let allocate = foreign("sk_matrix44_new", void @-> returning(t));
    let allocate_identity =
      foreign("sk_matrix44_new_identity", void @-> returning(t));
    let destroy = foreign("sk_matrix44_destroy", t @-> returning(void));

    let setRotateAboutDegrees =
      foreign(
        "sk_matrix44_set_rotate_about_degrees",
        t @-> float @-> float @-> float @-> float @-> returning(void),
      );
    let setRotateAboutRadians =
      foreign(
        "sk_matrix44_set_rotate_about_radians",
        t @-> float @-> float @-> float @-> float @-> returning(void),
      );

    let setTranslate =
      foreign(
        "sk_matrix44_set_translate",
        t @-> float @-> float @-> float @-> returning(void),
      );
    let preTranslate =
      foreign(
        "sk_matrix44_pre_translate",
        t @-> float @-> float @-> float @-> returning(void),
      );
    let postTranslate =
      foreign(
        "sk_matrix44_post_translate",
        t @-> float @-> float @-> float @-> returning(void),
      );

    let setScale =
      foreign(
        "sk_matrix44_set_scale",
        t @-> float @-> float @-> float @-> returning(void),
      );
    let preScale =
      foreign(
        "sk_matrix44_pre_scale",
        t @-> float @-> float @-> float @-> returning(void),
      );
    let postScale =
      foreign(
        "sk_matrix44_post_scale",
        t @-> float @-> float @-> float @-> returning(void),
      );

    let setConcat =
      foreign("sk_matrix44_set_concat", t @-> t @-> t @-> returning(void));
    let preConcat =
      foreign("sk_matrix44_pre_concat", t @-> t @-> returning(void));
    let postConcat =
      foreign("sk_matrix44_post_concat", t @-> t @-> returning(void));

    let get =
      foreign("sk_matrix44_get", t @-> int @-> int @-> returning(float));
    let set =
      foreign(
        "sk_matrix44_set",
        t @-> int @-> int @-> float @-> returning(void),
      );
    let toMatrix =
      foreign("sk_matrix44_to_matrix", t @-> Matrix.t @-> returning(void));
  };

  module RRect = {
    type t = ptr(structure(SkiaTypes.RRect.t));
    let t = ptr(SkiaTypes.RRect.t);

    type rRectType = SkiaTypes.RRect.rRectType;
    let rRectType = SkiaTypes.RRect.rRectType;

    type corner = SkiaTypes.RRect.corner;
    let corner = SkiaTypes.RRect.corner;

    let allocate = foreign("sk_rrect_new", void @-> returning(t));
    let allocateCopy = foreign("sk_rrect_new_copy", t @-> returning(t));
    let delete = foreign("sk_rrect_delete", t @-> returning(void));

    let getType = foreign("sk_rrect_get_type", t @-> returning(rRectType));
    let getRect =
      foreign("sk_rrect_get_rect", t @-> Rect.t @-> returning(void));
    let getRadii =
      foreign(
        "sk_rrect_get_radii",
        t @-> corner @-> Vector.t @-> returning(void),
      );
    let getWidth = foreign("sk_rrect_get_width", t @-> returning(float));
    let getHeight = foreign("sk_rrect_get_height", t @-> returning(float));
    let setEmpty = foreign("sk_rrect_set_empty", t @-> returning(void));
    let setRect =
      foreign("sk_rrect_set_rect", t @-> Rect.t @-> returning(void));
    let setOval =
      foreign("sk_rrect_set_oval", t @-> Rect.t @-> returning(void));
    let setRectXy =
      foreign(
        "sk_rrect_set_rect_xy",
        t @-> Rect.t @-> float @-> float @-> returning(void),
      );
    let setNinePatch =
      foreign(
        "sk_rrect_set_nine_patch",
        t
        @-> Rect.t
        @-> float
        @-> float
        @-> float
        @-> float
        @-> returning(void),
      );
    let setRectRadii =
      foreign(
        "sk_rrect_set_rect_radii",
        t @-> Rect.t @-> Vector.t @-> returning(void),
      );
    let inset =
      foreign("sk_rrect_inset", t @-> float @-> float @-> returning(void));
    let outset =
      foreign("sk_rrect_outset", t @-> float @-> float @-> returning(void));
    let offset =
      foreign("sk_rrect_offset", t @-> float @-> float @-> returning(void));
    let contains =
      foreign("sk_rrect_contains", t @-> Rect.t @-> returning(bool));
    let isValid = foreign("sk_rrect_is_valid", t @-> returning(bool));
    let transform =
      foreign(
        "sk_rrect_transform",
        t @-> Matrix.t @-> t @-> returning(bool),
      );
  };

  module Path = {
    type t = ptr(structure(SkiaTypes.Path.t));
    let t = ptr(SkiaTypes.Path.t);

    let allocate = foreign("sk_path_new", void @-> returning(t));
    let delete = foreign("sk_path_delete", t @-> returning(void));

    type arcSize = SkiaTypes.Path.arcSize;
    let arcSize = SkiaTypes.Path.arcSize;

    type pathDirection = SkiaTypes.Path.pathDirection;
    let pathDirection = SkiaTypes.Path.pathDirection;

    let addRoundRect =
      foreign(
        "sk_path_add_rounded_rect",
        t @-> Rect.t @-> float @-> float @-> pathDirection @-> returning(void),
      );
    let addCircle =
      foreign(
        "sk_path_add_circle",
        t @-> float @-> float @-> float @-> pathDirection @-> returning(void),
      );
    let moveTo =
      foreign("sk_path_move_to", t @-> float @-> float @-> returning(void));
    let rMoveTo =
      foreign("sk_path_rmove_to", t @-> float @-> float @-> returning(void));
    let lineTo =
      foreign("sk_path_line_to", t @-> float @-> float @-> returning(void));
    let rLineTo =
      foreign("sk_path_rline_to", t @-> float @-> float @-> returning(void));
    let cubicTo =
      foreign(
        "sk_path_cubic_to",
        t
        @-> float
        @-> float
        @-> float
        @-> float
        @-> float
        @-> float
        @-> returning(void),
      );
    let rCubicTo =
      foreign(
        "sk_path_rcubic_to",
        t
        @-> float
        @-> float
        @-> float
        @-> float
        @-> float
        @-> float
        @-> returning(void),
      );
    let quadTo =
      foreign(
        "sk_path_quad_to",
        t @-> float @-> float @-> float @-> float @-> returning(void),
      );
    let rQuadTo =
      foreign(
        "sk_path_rquad_to",
        t @-> float @-> float @-> float @-> float @-> returning(void),
      );
    let arcTo =
      foreign(
        "sk_path_arc_to",
        t
        @-> float
        @-> float
        @-> float
        @-> arcSize
        @-> pathDirection
        @-> float
        @-> float
        @-> returning(void),
      );
    let rArcTo =
      foreign(
        "sk_path_rarc_to",
        t
        @-> float
        @-> float
        @-> float
        @-> arcSize
        @-> pathDirection
        @-> float
        @-> float
        @-> returning(void),
      );
    let close = foreign("sk_path_close", t @-> returning(void));
  };

  module ColorSpace = {
    type t = ptr(structure(SkiaTypes.ColorSpace.t));
    let t = ptr(SkiaTypes.ColorSpace.t);
  };

  module Data = {
    type t = ptr(structure(SkiaTypes.Data.t));
    let t = ptr(SkiaTypes.Data.t);

    let makeFromFileName =
      foreign(
        "sk_data_new_from_file",
        string @-> returning(ptr_opt(SkiaTypes.Data.t)),
      );
    let delete = foreign("sk_data_unref", t @-> returning(void));

    let getData = foreign("sk_data_get_data", t @-> returning(ptr(void)));
    let getSize = foreign("sk_data_get_size", t @-> returning(size_t));
  };

  module ImageInfo = {
    type t = ptr(structure(SkiaTypes.ImageInfo.t));
    let t = ptr(SkiaTypes.ImageInfo.t);

    let make = (width, height, colorType, alphaType, colorSpace) => {
      let imageInfo = allocate_n(SkiaTypes.ImageInfo.t, ~count=1);
      setf(!@imageInfo, SkiaTypes.ImageInfo.width, width);
      setf(!@imageInfo, SkiaTypes.ImageInfo.height, height);
      setf(!@imageInfo, SkiaTypes.ImageInfo.colorType, colorType);
      setf(!@imageInfo, SkiaTypes.ImageInfo.alphaType, alphaType);
      setf(!@imageInfo, SkiaTypes.ImageInfo.colorSpace, colorSpace);
      imageInfo;
    };
  };

  module Image = {
    type t = ptr(structure(SkiaTypes.Image.t));
    let t = ptr(SkiaTypes.Image.t);

    let allocateFromEncoded =
      foreign(
        "sk_image_new_from_encoded",
        Data.t
        @-> ptr_opt(SkiaTypes.IRect.t)
        @-> returning(ptr_opt(SkiaTypes.Image.t)),
      );
    let delete = foreign("sk_image_unref", t @-> returning(void));

    let encode = foreign("sk_image_encode", t @-> returning(Data.t));
  };

  type pixelGeometry = SkiaTypes.pixelGeometry;
  let pixelGeometry = SkiaTypes.pixelGeometry;

  module Gr = {
    type surfaceOrigin = SkiaTypes.Gr.surfaceOrigin;
    let surfaceOrigin = SkiaTypes.Gr.surfaceOrigin;

    module Gl = {
      module Interface = {
        type t = ptr(structure(SkiaTypes.Gr.Gl.Interface.t));
        let t = ptr(SkiaTypes.Gr.Gl.Interface.t);

        let makeNative =
          foreign(
            "gr_glinterface_create_native_interface",
            void @-> returning(ptr_opt(SkiaTypes.Gr.Gl.Interface.t)),
          );

        let makeSdl2 =
          foreign(
            "reason_skia_make_sdl2_interface",
            void @-> returning(ptr_opt(SkiaTypes.Gr.Gl.Interface.t)),
          );
      };

      module FramebufferInfo = {
        type t = ptr(structure(SkiaTypes.Gr.Gl.FramebufferInfo.t));
        let t = ptr(SkiaTypes.Gr.Gl.FramebufferInfo.t);

        let make = (framebufferObjectId, format) => {
          let framebufferInfo =
            allocate_n(SkiaTypes.Gr.Gl.FramebufferInfo.t, ~count=1);
          setf(
            !@framebufferInfo,
            SkiaTypes.Gr.Gl.FramebufferInfo.framebufferObjectId,
            framebufferObjectId,
          );
          setf(
            !@framebufferInfo,
            SkiaTypes.Gr.Gl.FramebufferInfo.format,
            format,
          );
          framebufferInfo;
        };
      };
    };

    module Context = {
      type t = ptr(structure(SkiaTypes.Gr.Context.t));
      let t = ptr(SkiaTypes.Gr.Context.t);

      let makeGl =
        foreign(
          "gr_context_make_gl",
          ptr_opt(SkiaTypes.Gr.Gl.Interface.t)
          @-> returning(ptr_opt(SkiaTypes.Gr.Context.t)),
        );
    };

    module BackendRenderTarget = {
      type t = ptr(structure(SkiaTypes.Gr.BackendRenderTarget.t));
      let t = ptr(SkiaTypes.Gr.BackendRenderTarget.t);

      let makeGl =
        foreign(
          "gr_backendrendertarget_new_gl",
          int
          @-> int
          @-> int
          @-> int
          @-> Gl.FramebufferInfo.t
          @-> returning(t),
        );
    };
  };

  type clipOp = SkiaTypes.clipOp;
  let clipOp = SkiaTypes.clipOp;

  module Canvas = {
    type t = ptr(structure(SkiaTypes.Canvas.t));
    let t = ptr(SkiaTypes.Canvas.t);

    let clear =
      foreign("sk_canvas_clear", t @-> Color.t @-> returning(void));

    let drawPaint =
      foreign("sk_canvas_draw_paint", t @-> Paint.t @-> returning(void));
    let drawRect =
      foreign(
        "sk_canvas_draw_rect",
        t @-> Rect.t @-> Paint.t @-> returning(void),
      );
    let drawRectLtwh =
      foreign(
        "reason_skia_stub_sk_canvas_draw_rect_ltwh",
        t
        @-> float
        @-> float
        @-> float
        @-> float
        @-> Paint.t
        @-> returning(void),
      );
    let drawRoundRect =
      foreign(
        "sk_canvas_draw_round_rect",
        t @-> Rect.t @-> float @-> float @-> Paint.t @-> returning(void),
      );
    let drawOval =
      foreign(
        "sk_canvas_draw_oval",
        t @-> Rect.t @-> Paint.t @-> returning(void),
      );
    let drawCircle =
      foreign(
        "sk_canvas_draw_circle",
        t @-> float @-> float @-> float @-> Paint.t @-> returning(void),
      );
    let drawRRect =
      foreign(
        "sk_canvas_draw_rrect",
        t @-> RRect.t @-> Paint.t @-> returning(void),
      );
    let drawPath =
      foreign(
        "sk_canvas_draw_path",
        t @-> Path.t @-> Paint.t @-> returning(void),
      );

    let drawText =
      foreign(
        "sk_canvas_draw_text",
        t
        @-> string
        @-> int
        @-> float
        @-> float
        @-> Paint.t
        @-> returning(void),
      );

    let drawImage =
      foreign(
        "sk_canvas_draw_image",
        t
        @-> Image.t
        @-> float
        @-> float
        @-> ptr_opt(SkiaTypes.Paint.t)
        @-> returning(void),
      );

    let drawImageRect =
      foreign(
        "sk_canvas_draw_image_rect",
        t
        @-> Image.t
        @-> ptr_opt(SkiaTypes.Rect.t)
        @-> ptr(SkiaTypes.Rect.t)
        @-> ptr_opt(SkiaTypes.Paint.t)
        @-> returning(void),
      );

    let concat =
      foreign("sk_canvas_concat", t @-> Matrix.t @-> returning(void));
    let setMatrix =
      foreign("sk_canvas_set_matrix", t @-> Matrix.t @-> returning(void));
    let translate =
      foreign(
        "sk_canvas_translate",
        t @-> float @-> float @-> returning(void),
      );
    let scale =
      foreign("sk_canvas_scale", t @-> float @-> float @-> returning(void));
    let rotate =
      foreign("sk_canvas_rotate_degrees", t @-> float @-> returning(void));
    let skew =
      foreign("sk_canvas_skew", t @-> float @-> float @-> returning(void));
    let resetMatrix =
      foreign("sk_canvas_reset_matrix", t @-> returning(void));

    let clipRect =
      foreign(
        "sk_canvas_clip_rect_with_operation",
        t @-> Rect.t @-> clipOp @-> bool @-> returning(void),
      );
    let clipPath =
      foreign(
        "sk_canvas_clip_path_with_operation",
        t @-> Path.t @-> clipOp @-> bool @-> returning(void),
      );
    let clipRRect =
      foreign(
        "sk_canvas_clip_rrect_with_operation",
        t @-> RRect.t @-> clipOp @-> bool @-> returning(void),
      );

    let save = foreign("sk_canvas_save", t @-> returning(int));
    let saveLayer =
      foreign(
        "sk_canvas_save_layer",
        t
        @-> ptr_opt(SkiaTypes.Rect.t)
        @-> ptr_opt(SkiaTypes.Paint.t)
        @-> returning(int),
      );
    let restore = foreign("sk_canvas_restore", t @-> returning(void));

    let flush = foreign("sk_canvas_flush", t @-> returning(void));
  };

  module SurfaceProps = {
    type t = ptr(structure(SkiaTypes.SurfaceProps.t));
    let t = ptr(SkiaTypes.SurfaceProps.t);

    let make =
      foreign(
        "sk_surfaceprops_new",
        uint32_t @-> pixelGeometry @-> returning(t),
      );
  };

  module Surface = {
    type t = ptr(structure(SkiaTypes.Surface.t));
    let t = ptr(SkiaTypes.Surface.t);

    let allocateRaster =
      foreign(
        "sk_surface_new_raster",
        ImageInfo.t
        @-> size_t
        @-> ptr_opt(SkiaTypes.SurfaceProps.t)
        @-> returning(t),
      );
    let allocateRenderTarget =
      foreign(
        "sk_surface_new_render_target",
        Gr.Context.t
        @-> bool
        @-> ImageInfo.t
        @-> int
        @-> Gr.surfaceOrigin
        @-> ptr_opt(SkiaTypes.SurfaceProps.t)
        @-> bool
        @-> returning(ptr_opt(SkiaTypes.Surface.t)),
      );
    let allocateFromBackendRenderTarget =
      foreign(
        "sk_surface_new_backend_render_target",
        Gr.Context.t
        @-> Gr.BackendRenderTarget.t
        @-> Gr.surfaceOrigin
        @-> colorType
        @-> ptr_opt(SkiaTypes.ColorSpace.t)
        @-> ptr_opt(SkiaTypes.SurfaceProps.t)
        @-> returning(ptr_opt(SkiaTypes.Surface.t)),
      );
    let delete = foreign("sk_surface_unref", t @-> returning(void));

    let getCanvas =
      foreign("sk_surface_get_canvas", t @-> returning(Canvas.t));
    let allocateImageSnapshot =
      foreign("sk_surface_new_image_snapshot", t @-> returning(Image.t));

    let getWidth = foreign("sk_surface_get_width", t @-> returning(int));
    let getHeight = foreign("sk_surface_get_height", t @-> returning(int));
    let getProps =
      foreign("sk_surface_get_props", t @-> returning(SurfaceProps.t));
  };
};
