
undefined4 FUN_006435ca(char *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  
  if (DAT_00703c48 == (code *)0x0) {
    iVar1 = FUN_00643cfb();
    if (iVar1 == 0) {
      DAT_00703c48 = FUN_00643d31;
    }
    else {
      DAT_00703c48 = GetLocaleInfoA_exref;
    }
  }
  if (param_1 != (char *)0x0) {
    DAT_00703c38 = param_1;
    if (*param_1 != '\0') {
      FUN_00643747(&PTR_s_american_006dda90,0x40,&DAT_00703c38);
    }
    DAT_00703c3c = param_1 + 0x40;
    if ((DAT_00703c3c != (char *)0x0) && (*DAT_00703c3c != '\0')) {
      FUN_00643747(&PTR_s_america_006dd9d8,0x16,&DAT_00703c3c);
    }
    DAT_00703c40 = 0;
    if ((DAT_00703c38 != (char *)0x0) && (*DAT_00703c38 != '\0')) {
      if ((DAT_00703c3c == (char *)0x0) || (*DAT_00703c3c == '\0')) {
        FUN_00643a2a();
      }
      else {
        FUN_0064379f();
      }
      goto LAB_00643687;
    }
    if ((DAT_00703c3c != (char *)0x0) && (*DAT_00703c3c != '\0')) {
      FUN_00643b3d();
      goto LAB_00643687;
    }
  }
  FUN_00643bfa();
LAB_00643687:
  if ((((DAT_00703c40 == 0) || (uVar2 = FUN_00643c14(param_1 + 0x80), uVar2 == 0)) ||
      (BVar3 = IsValidCodePage(uVar2 & 0xffff), BVar3 == 0)) ||
     (BVar3 = IsValidLocale(DAT_00703c28,1), BVar3 == 0)) {
    return 0;
  }
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = (undefined2)DAT_00703c28;
    param_2[1] = (undefined2)DAT_00703c44;
    param_2[2] = (short)uVar2;
  }
  if (param_3 != 0) {
    iVar1 = (*DAT_00703c48)(DAT_00703c28,0x1001,param_3,0x40);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (*DAT_00703c48)(DAT_00703c44,0x1002,param_3 + 0x40,0x40);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0063b26a(uVar2,param_3 + 0x80,10);
  }
  return 1;
}

