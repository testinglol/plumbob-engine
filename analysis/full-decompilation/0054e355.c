
undefined4 FUN_0054e355(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f5394 == (int *)0x0) {
    FUN_005a5631(0x1541,&DAT_006f5394,4);
    FUN_005a5631(0x1586,&DAT_006f5398,4);
    (**(code **)(*DAT_006f5394 + 0x68))(DAT_006f2a64);
    (**(code **)(*DAT_006f5398 + 0x68))(DAT_006f2a64);
  }
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 != '\0') {
    uVar2 = thunk_FUN_005dbf32();
    goto LAB_0054e53c;
  }
  cVar1 = thunk_FUN_005dbf32();
  if (cVar1 != '\0') {
    if (DAT_006f5390 == (int *)0x0) {
      if (extraout_ECX[0x91] == 0) {
        if (extraout_ECX[0x92] != 0) {
          pvVar3 = operator_new(0x104);
          *(void **)(unaff_EBP + -0x10) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar3 == (void *)0x0) goto LAB_0054e4e4;
          DAT_006f5390 = (int *)FUN_0054f8b1(extraout_ECX[0x92]);
          goto LAB_0054e4e6;
        }
        if (extraout_ECX[0x93] != 0) {
          pvVar3 = operator_new(0x104);
          *(void **)(unaff_EBP + -0x10) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar3 == (void *)0x0) goto LAB_0054e4e4;
          DAT_006f5390 = (int *)FUN_0054f8f2(extraout_ECX[0x93]);
          goto LAB_0054e4e6;
        }
        if (extraout_ECX[0x94] != 0) {
          pvVar3 = operator_new(0x104);
          *(void **)(unaff_EBP + -0x10) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          if (pvVar3 == (void *)0x0) goto LAB_0054e4e4;
          DAT_006f5390 = (int *)FUN_0054f92a(extraout_ECX[0x94]);
          goto LAB_0054e4e6;
        }
        if (extraout_ECX[0x95] != 0) {
          pvVar3 = operator_new(0x104);
          *(void **)(unaff_EBP + -0x10) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 4;
          if (pvVar3 == (void *)0x0) goto LAB_0054e4e4;
          DAT_006f5390 = (int *)FUN_0054f96b(extraout_ECX[0x95]);
          goto LAB_0054e4e6;
        }
      }
      else {
        pvVar3 = operator_new(0x104);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
LAB_0054e4e4:
          DAT_006f5390 = (int *)0x0;
        }
        else {
          DAT_006f5390 = (int *)FUN_0054f854(extraout_ECX[0x91]);
        }
LAB_0054e4e6:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (DAT_006f5390 != (int *)0x0) {
          (**(code **)(*DAT_006f5390 + 0xc))();
          goto LAB_0054e505;
        }
      }
      uVar2 = 0;
      goto LAB_0054e53c;
    }
LAB_0054e505:
    (**(code **)(*DAT_006f5390 + 4))();
    (**(code **)(*extraout_ECX + 0x90))(0x400,1);
    (**(code **)(*extraout_ECX + 0x90))(0x200,1);
    extraout_ECX[0x29] = 0;
    FUN_0054f3dc(0);
  }
  uVar2 = 1;
LAB_0054e53c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

