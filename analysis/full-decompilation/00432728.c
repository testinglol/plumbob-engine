
void __thiscall
FUN_00432728(undefined1 *param_1,undefined4 *param_2,undefined4 param_3,int param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 1;
  puVar1 = (undefined4 *)(param_4 + 0xf4);
  if (param_4 == 0) {
    puVar1 = param_2;
  }
  *(undefined4 *)(param_1 + 4) = *puVar1;
  *(undefined4 *)(param_1 + 8) = puVar1[1];
  *(int *)(param_1 + 0xc) = param_4;
  if (param_4 == 0) {
    param_5 = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x10) = param_5;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  return;
}

