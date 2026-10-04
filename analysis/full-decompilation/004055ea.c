
void __thiscall FUN_004055ea(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[1];
  uVar2 = (iVar1 - *param_1) / 0x3c0;
  if (param_2 < uVar2) {
    FUN_0040564f(param_2 * 0x3c0 + *param_1,iVar1);
  }
  else {
    FUN_00405851(iVar1,param_2 - uVar2,param_3);
  }
  return;
}

