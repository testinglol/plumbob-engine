
undefined4 __fastcall FUN_00500c4f(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    if (param_1[0x57] != 0) {
      FUN_0050848f();
      FUN_005da4c7(param_1[0x57]);
      param_1[0x57] = 0;
    }
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    piVar4 = param_1 + 0x3d;
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    if (((param_1[0x4a] - param_1[0x49] & 0xfffffffcU) != 0) &&
       (uVar2 = 0, param_1[0x4a] - param_1[0x49] >> 2 != 0)) {
      do {
        *(undefined4 *)(param_1[0x49] + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)(param_1[0x4a] - param_1[0x49] >> 2));
    }
    if ((undefined4 *)param_1[0x5f] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x5f])(1);
    }
    param_1[0x5f] = 0;
    if ((undefined4 *)param_1[0x60] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x60])(1);
    }
    param_1[0x60] = 0;
    FUN_005dbf4d();
  }
  return 1;
}

