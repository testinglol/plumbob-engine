
void FUN_004664bd(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_00466583(param_1);
  if (iVar2 == 0) {
    uVar3 = 0xffffff9d;
    *param_2 = 0;
  }
  else {
    uVar1 = FUN_0060b844();
    uVar3 = 0;
    *param_2 = uVar1;
  }
  FUN_004659fc(uVar3);
  return;
}

