
uint __fastcall FUN_0041ca91(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  uVar2 = FUN_00401f6f();
  if (uVar2 != 0) {
    return uVar2 & 0xffff0000;
  }
  return CONCAT22((short)((uint)param_1[6] >> 0x10),*(undefined2 *)(param_1[6] + 0x10));
}

