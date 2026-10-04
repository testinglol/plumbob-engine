
undefined4 FUN_0056f32e(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  
  FUN_00634c24();
  puVar1 = DAT_006f627c;
  if (DAT_006f627c == (undefined4 *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0x3f000000;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = DAT_006f627c[5];
    uVar3 = extraout_ECX;
    uVar5 = extraout_ECX;
    iVar2 = _strcmp(*(char **)(unaff_EBP + 8),(char *)(puVar1 + 6));
    if (iVar2 == 0) {
      uVar3 = 0;
      goto LAB_0056f3c1;
    }
    if (DAT_006f627c != (undefined4 *)0x0) {
      (**(code **)*DAT_006f627c)(1,uVar3,uVar5);
    }
  }
  pvVar4 = operator_new(0x11c);
  *(void **)(unaff_EBP + -0x14) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    DAT_006f627c = (undefined4 *)0x0;
  }
  else {
    DAT_006f627c = (undefined4 *)
                   FUN_0056f6bb(*(undefined4 *)(DAT_006e486c + 0x30),
                                *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004a6a39();
  uVar3 = 1;
LAB_0056f3c1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

