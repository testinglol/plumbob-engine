
void __thiscall FUN_0059796c(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 0;
  piVar1 = (int *)(param_1 + 0x6c);
  if (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x6c) >> 2 != 0) {
    piVar3 = (int *)*piVar1;
    do {
      if (*piVar3 == param_2) {
        FUN_005db2f2((int *)*piVar1 + uVar2);
        if ((*(int *)(param_1 + 0x70) - *piVar1 & 0xfffffffcU) == 0) {
          *(undefined4 *)(param_1 + 0x78) = DAT_006e5490;
        }
        FUN_005977a1();
        return;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x70) - *piVar1 >> 2));
  }
  return;
}

