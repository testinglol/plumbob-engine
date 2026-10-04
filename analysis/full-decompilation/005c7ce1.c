
void __thiscall FUN_005c7ce1(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_005d30ec(param_2);
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00677308,(undefined4 *)(param_1 + 8));
    if (iVar2 < 0) {
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  return;
}

