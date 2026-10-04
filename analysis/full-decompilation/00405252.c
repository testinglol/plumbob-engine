
undefined4 __thiscall FUN_00405252(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 1) {
    uVar1 = 0;
  }
  else if (param_2 < 0xb) {
    uVar1 = *(undefined4 *)(*param_1 + param_2 * 4);
  }
  else {
    uVar1 = 10;
  }
  return uVar1;
}

