
void __fastcall FUN_004f73fa(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(param_1 + 0xad) != '\0') {
    if (*(char *)(param_1 + 0xc4) != '\0') {
      if (DAT_006c9f58 != '\0') {
        FUN_004fb1a5();
      }
      *(undefined1 *)(param_1 + 0xc4) = 0;
      return;
    }
    if (*(char *)(param_1 + 0xb1) == '\0') {
      if (*(char *)(param_1 + 0xb2) == '\0') {
        if (*(char *)(param_1 + 0xb3) == '\0') {
          if (*(char *)(param_1 + 0xb4) == '\0') {
            if (*(char *)(param_1 + 0xb5) == '\0') {
              return;
            }
            *(undefined1 *)(param_1 + 0xb5) = 0;
            FUN_004df9a5(s_Entering_Magicland_Screen_006cb348);
            FUN_004f62eb();
            pcVar1 = s_Leaving_Magicland_Screen_006cb32c;
          }
          else {
            *(undefined1 *)(param_1 + 0xb4) = 0;
            FUN_004df9a5(s_Entering_Studiotown_Screen_006cb380);
            FUN_004f613c();
            pcVar1 = s_Leaving_Studiotown_Screen_006cb364;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0xb3) = 0;
          FUN_004df9a5(s_Entering_Vacation_Screen_006cb3b4);
          FUN_004f5f8d();
          pcVar1 = s_Leaving_Vacation_Screen_006cb39c;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xb2) = 0;
        FUN_004df9a5(s_Entering_Downtown_Screen_006cb3e8);
        FUN_004f5dde();
        pcVar1 = s_Leaving_Downtown_Screen_006cb3d0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xb1) = 0;
      FUN_004df9a5(s_Entering_Neighborhood_Screen_006cb420);
      FUN_004f5bb5();
      pcVar1 = s_Leaving_Neighborhood_Screen_006cb404;
    }
    FUN_004df9a5(pcVar1);
    return;
  }
  if (*(char *)(param_1 + 0xb1) == '\0') {
    if (*(char *)(param_1 + 0xb2) == '\0') {
      if (*(char *)(param_1 + 0xb3) == '\0') {
        if (*(char *)(param_1 + 0xb4) == '\0') {
          if (*(char *)(param_1 + 0xb5) == '\0') goto LAB_004f75ea;
          *(undefined1 *)(param_1 + 0xb5) = 0;
          FUN_004df9a5(s_Entering_Magicland_Screen_006cb348);
          FUN_004f62eb();
          pcVar1 = s_Leaving_Magicland_Screen_006cb32c;
        }
        else {
          *(undefined1 *)(param_1 + 0xb4) = 0;
          FUN_004df9a5(s_Entering_Studiotown_Screen_006cb380);
          FUN_004f613c();
          pcVar1 = s_Leaving_Studiotown_Screen_006cb364;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xb3) = 0;
        FUN_004df9a5(s_Entering_Vacation_Screen_006cb3b4);
        FUN_004f5f8d();
        pcVar1 = s_Leaving_Vacation_Screen_006cb39c;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xb2) = 0;
      FUN_004df9a5(s_Entering_Downtown_Screen_006cb3e8);
      FUN_004f5dde();
      pcVar1 = s_Leaving_Downtown_Screen_006cb3d0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xb1) = 0;
    FUN_004df9a5(s_Entering_Neighborhood_Screen_006cb420);
    FUN_004f5bb5();
    pcVar1 = s_Leaving_Neighborhood_Screen_006cb404;
  }
  FUN_004df9a5(pcVar1);
LAB_004f75ea:
  if (*(char *)(param_1 + 0xe8) == '\x01') {
    FUN_004fc63a();
  }
  FUN_004fadfb(0);
  FUN_004f7613();
  FUN_004d1aa0();
  return;
}

