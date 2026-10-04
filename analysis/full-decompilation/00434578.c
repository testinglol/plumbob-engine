
void __thiscall FUN_00434578(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_c;
  int local_8;
  
  if (4 < param_3) {
    piVar1 = (int *)(param_1 + 0x130);
    local_8 = (*(int *)(param_1 + 0x134) - *piVar1) / 0x24;
    FUN_00464973(&local_8,1);
    iVar4 = 0;
    uVar3 = 0;
    if (0 < (short)local_8) {
      do {
        local_c = 0;
        param_3 = 0;
        while ((uint)((*(int *)(param_1 + 0x134) - *piVar1) / 0x24) <= uVar3) {
          uVar2 = FUN_0046dfaf();
          FUN_00435b8c(uVar2);
        }
        local_c = 0;
        param_3 = CONCAT22((short)((uint)*piVar1 >> 0x10),*(undefined2 *)(*piVar1 + 0x10 + iVar4));
        FUN_00464973(&local_c,1);
        FUN_00464973(&param_3,1);
        uVar3 = uVar3 + 1;
        *(undefined2 *)(*piVar1 + 0x10 + iVar4) = (undefined2)param_3;
        iVar4 = iVar4 + 0x24;
      } while ((int)uVar3 < (int)(short)local_8);
    }
  }
  return;
}

