
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056f23d(void)

{
  float fVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (_DAT_0066657c < *(float *)(unaff_EBP + 8)) {
    fVar1 = _DAT_0066740c;
    if (_DAT_0066740c < *(float *)(unaff_EBP + 8)) goto LAB_0056f26f;
  }
  else {
    fVar1 = 0.0;
LAB_0056f26f:
    *(float *)(unaff_EBP + 8) = fVar1;
  }
  if (DAT_006f627c == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)&DAT_006de560;
  }
  else {
    uVar4 = 0;
    if (ABS(*(float *)(unaff_EBP + 8) - (float)DAT_006f627c[5]) <= _DAT_0067343c) goto LAB_0056f30e;
    puVar2 = DAT_006f627c + 6;
  }
  FUN_006358b0(unaff_EBP + -0x110,puVar2);
  if (DAT_006f627c != (undefined4 *)0x0) {
    (**(code **)*DAT_006f627c)(1);
  }
  pvVar3 = operator_new(0x11c);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    DAT_006f627c = (undefined4 *)0x0;
  }
  else {
    DAT_006f627c = (undefined4 *)
                   FUN_0056f6bb(*(undefined4 *)(DAT_006e486c + 0x30),*(undefined4 *)(unaff_EBP + 8),
                                unaff_EBP + -0x110);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004a6a39();
  uVar4 = 1;
LAB_0056f30e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

