
void __fastcall FUN_0053da3a(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 != *(int *)(param_1 + 0x34)) {
    do {
      cVar1 = *(char *)(iVar2 + 1);
      if ((((cVar1 == '\x02') || (cVar1 == '\f')) || (cVar1 == '\r')) || (cVar1 == '\x0e')) {
        if (cVar1 == '\x02') {
LAB_0053da7f:
          uVar4 = 0xf8;
        }
        else if (cVar1 == '\f') {
          uVar4 = 0xf9;
        }
        else if (cVar1 == '\r') {
          uVar4 = 0xfa;
        }
        else {
          if (cVar1 != '\x0e') goto LAB_0053da7f;
          uVar4 = 0xfb;
        }
        if (*(short *)(iVar2 + 2 + *(int *)(param_1 + 0x18) * 2) == 0) {
          *(undefined2 *)(iVar2 + 2 + *(int *)(param_1 + 0x18) * 2) = uVar4;
        }
        uVar3 = (uint)(*(int *)(param_1 + 0x18) == 0);
        if (*(short *)(iVar2 + 2 + uVar3 * 2) == 0) {
          *(undefined2 *)(iVar2 + 2 + uVar3 * 2) = uVar4;
        }
      }
      iVar2 = iVar2 + 6;
    } while (iVar2 != *(int *)(param_1 + 0x34));
  }
  return;
}

