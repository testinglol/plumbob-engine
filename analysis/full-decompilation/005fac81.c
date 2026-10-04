
undefined1 __thiscall FUN_005fac81(int param_1,float param_2,float param_3,float param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  if (*(char *)(param_1 + 0x2c) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + -0x14c);
    *(float *)(param_1 + 0x38) = param_2;
    *(float *)(param_1 + 0x3c) = param_3;
    *(float *)(param_1 + 0x40) = param_4;
    param_2 = param_2 - *(float *)(DAT_006fed78 + 0x14);
    param_3 = param_3 - *(float *)(DAT_006fed78 + 0x18);
    param_4 = param_4 - *(float *)(DAT_006fed78 + 0x1c);
    FUN_00636264((double)(param_4 * param_4 + param_3 * param_3 + param_2 * param_2));
    uVar4 = __ftol();
    *(undefined4 *)(param_1 + 0x30) = uVar4;
    uVar5 = FUN_005f94c1();
    *(undefined4 *)(param_1 + -0x14c) = uVar2;
  }
  else {
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 == (int *)0x0) {
      uVar5 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1,param_2,param_3,param_4,0);
      uVar5 = iVar3 == 0;
    }
  }
  return uVar5;
}

