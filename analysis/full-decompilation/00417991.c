
uint __thiscall FUN_00417991(int *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar6 = 0xffffffcf;
  }
  else {
    uVar6 = 0;
  }
  FUN_004659fc(uVar6);
  uVar2 = FUN_00401f6f();
  if (uVar2 != 0) {
    return uVar2 & 0xffff0000;
  }
  puVar3 = (undefined4 *)param_1[6];
  iVar5 = 0x80;
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) goto LAB_004179e9;
    iVar4 = puVar3[1];
    if (iVar4 == param_2) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  for (puVar3 = (undefined4 *)puVar3[2]; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3
      ) {
    iVar4 = CONCAT22((short)((uint)iVar4 >> 0x10),*(short *)(puVar3 + 1));
    if ((short)iVar5 < *(short *)(puVar3 + 1)) {
      iVar5 = iVar4;
    }
  }
LAB_004179e9:
  return iVar5 + 1;
}

