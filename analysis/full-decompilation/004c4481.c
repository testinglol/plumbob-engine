
void __thiscall
FUN_004c4481(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined1 uVar1;
  undefined4 uVar2;
  char cVar3;
  
  cVar3 = FUN_004b465e();
  if (cVar3 != '\0') {
    cVar3 = FUN_004b4665();
    if (cVar3 != '\0') {
      uVar1 = *(undefined1 *)(param_1 + 0x1c);
      uVar2 = *(undefined4 *)(param_1 + 0x18);
      *(undefined1 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
      FUN_004c44da(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      *(undefined4 *)(param_1 + 0x18) = uVar2;
      *(undefined1 *)(param_1 + 0x1c) = uVar1;
    }
  }
  return;
}

