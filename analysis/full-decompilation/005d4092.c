
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005d4092(void)

{
  char *_Str1;
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  **(undefined4 **)(unaff_EBP + 8) = 0;
  _memset((void *)(unaff_EBP + -100),0,0x50);
  *(undefined4 *)(unaff_EBP + -100) = 0x50;
  _Str1 = *(char **)(unaff_EBP + 0xc);
  iVar1 = _strcmp(_Str1,&DAT_006d6470);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP + -0x60) = 0x3f800000;
    *(undefined4 *)(unaff_EBP + -0x5c) = 0;
    *(undefined4 *)(unaff_EBP + -0x58) = 0;
    *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
    uVar4 = 0x3f800000;
LAB_005d4298:
    *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
    uVar4 = 0;
LAB_005d429d:
    *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
    uVar4 = 0;
LAB_005d441e:
    *(undefined4 *)(unaff_EBP + -0x48) = uVar4;
LAB_005d4421:
    *(undefined4 *)(unaff_EBP + -0x44) = 0x3f800000;
LAB_005d4426:
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0x40a00000;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(iVar1 + 8) + 0x68);
    pvVar2 = operator_new(0x90);
    *(void **)(unaff_EBP + 0xc) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005d455a(*extraout_ECX,unaff_EBP + -100,_Str1,
                                   *(undefined4 *)(unaff_EBP + -0x10));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + -0x14) = piVar3;
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x64f4ffff;
      goto LAB_005d44be;
    }
    (**(code **)(*piVar3 + 4))();
    iVar1 = FUN_005d4615();
    piVar3 = *(int **)(unaff_EBP + -0x14);
    if (iVar1 == 0) {
      iVar1 = FUN_005d4650();
      if (iVar1 == 0) {
        FUN_005d15c0(unaff_EBP + -0x14);
        uVar4 = *(undefined4 *)(unaff_EBP + -0x14);
LAB_005d44b0:
        **(undefined4 **)(unaff_EBP + 8) = uVar4;
        iVar1 = 0;
        goto LAB_005d44be;
      }
      piVar3 = *(int **)(unaff_EBP + -0x14);
    }
  }
  else {
    iVar1 = _strcmp(_Str1,&DAT_006d6468);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = 0;
      uVar4 = 0;
LAB_005d43fd:
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      uVar4 = 0x3f800000;
      goto LAB_005d441e;
    }
    iVar1 = _strcmp(_Str1,s_black_006d6460);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0;
      uVar4 = 0;
LAB_005d428e:
      *(undefined4 *)(unaff_EBP + -0x58) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      uVar4 = 0;
      goto LAB_005d4298;
    }
    iVar1 = _strcmp(_Str1,&DAT_006d6458);
    if ((iVar1 == 0) || (iVar1 = _strcmp(_Str1,&DAT_006d6450), iVar1 == 0)) {
      uVar4 = _DAT_00666578;
      *(undefined4 *)(unaff_EBP + -0x60) = _DAT_00666578;
      *(undefined4 *)(unaff_EBP + -0x5c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x58) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
LAB_005d441b:
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      goto LAB_005d441e;
    }
    iVar1 = _strcmp(_Str1,s_yellow_006d6448);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x58) = 0;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      uVar4 = 0x3f800000;
LAB_005d4193:
      *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
      uVar4 = 0x3f800000;
      goto LAB_005d429d;
    }
    iVar1 = _strcmp(_Str1,s_green_006d6440);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x58) = 0;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      uVar4 = 0;
      goto LAB_005d4193;
    }
    iVar1 = _strcmp(_Str1,s_default_006c0a4c);
    if ((iVar1 == 0) || (iVar1 = _strcmp(_Str1,s_white_006d6438), iVar1 == 0)) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = 0x3f800000;
      uVar4 = 0x3f800000;
      goto LAB_005d43fd;
    }
    iVar1 = _strcmp(_Str1,s_BeigeMatte_006d642c);
    uVar4 = _DAT_00666a40;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3dcccccd;
      *(undefined4 *)(unaff_EBP + -0x48) = 0x3dcccccd;
      *(undefined4 *)(unaff_EBP + -0x60) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x5c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      goto LAB_005d4421;
    }
    iVar1 = _strcmp(_Str1,s_Jeans_006d6424);
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0x3ea6a6a7;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3ef8f8f9;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3f33b3b4;
      *(undefined4 *)(unaff_EBP + -0x50) = 0x3e808081;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0x3e868687;
      *(undefined4 *)(unaff_EBP + -0x48) = 0x3eb2b2b3;
      goto LAB_005d4421;
    }
    iVar1 = _strcmp(_Str1,s_Shoes_006d641c);
    uVar4 = _DAT_0067363c;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = _DAT_0067363c;
      *(undefined4 *)(unaff_EBP + -0x5c) = uVar4;
      goto LAB_005d428e;
    }
    iVar1 = _strcmp(_Str1,s_T_shirt_006d6414);
    uVar4 = _DAT_00673638;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x60) = 0x3f72f2f3;
      *(undefined4 *)(unaff_EBP + -0x50) = 0x3f47c7c8;
      *(undefined4 *)(unaff_EBP + -0x5c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x58) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      goto LAB_005d441b;
    }
    iVar1 = _strcmp(_Str1,s_Flesh_006d638c);
    uVar4 = _DAT_00673634;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3f38b8b9;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3f2aaaab;
      *(undefined4 *)(unaff_EBP + -0x60) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0x3f38b8b9;
      *(undefined4 *)(unaff_EBP + -0x48) = 0x3f2aaaab;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
      goto LAB_005d4421;
    }
    iVar1 = _strcmp(_Str1,&DAT_006d640c);
    uVar4 = _DAT_00666a44;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x3eb4b4b5;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x3ea4a4a5;
      *(undefined4 *)(unaff_EBP + -0x60) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0x3eb4b4b5;
      *(undefined4 *)(unaff_EBP + -0x48) = 0x3ea4a4a5;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
      goto LAB_005d4421;
    }
    if (*extraout_ECX == 0) goto LAB_005d4426;
    iVar1 = FUN_005cfd89(unaff_EBP + -0x10,_Str1);
    if (iVar1 == 0) {
      iVar1 = FUN_005d4092(unaff_EBP + 0xc,s_default_006c0a4c);
      if (iVar1 != 0) {
LAB_005d43bf:
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 8))();
        }
        goto LAB_005d44be;
      }
      iVar1 = FUN_005d46b0(*(undefined4 *)(unaff_EBP + -0x10));
      if (iVar1 != 0) {
        if (*(int **)(unaff_EBP + 0xc) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + 0xc) + 8))();
          *(undefined4 *)(unaff_EBP + 0xc) = 0;
        }
        goto LAB_005d43bf;
      }
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 8))();
      uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
      goto LAB_005d44b0;
    }
    piVar3 = *(int **)(unaff_EBP + -0x10);
    if (piVar3 == (int *)0x0) goto LAB_005d44be;
  }
  (**(code **)(*piVar3 + 8))();
LAB_005d44be:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

