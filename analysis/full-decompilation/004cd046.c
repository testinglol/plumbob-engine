
void __thiscall
FUN_004cd046(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int *piVar2;
  
  *(undefined4 *)(param_1 + 0x24) = 5;
  FUN_005a5e48(param_4);
  *(undefined4 *)(param_1 + 0x38) = param_3;
  FUN_005d499c(param_5);
  FUN_005d499c(param_6);
  *(undefined4 *)(param_1 + 0x1c) = param_7;
  cVar1 = FUN_005a5e72();
  if (cVar1 != '\0') {
    piVar2 = (int *)FUN_004096c2();
    (**(code **)(*piVar2 + 0x68))(DAT_006f2a64);
  }
  FUN_004cc877(param_2,4);
  return;
}

