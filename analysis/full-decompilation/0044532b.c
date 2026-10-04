
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044532b(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  for (local_8 = *(int *)(param_1 + 0x30); local_8 != 0; local_8 = *(int *)(local_8 + 0xe0)) {
    if (*(short *)(local_8 + 0x68) == 0) {
      if (0 < *(short *)(local_8 + 0x98)) {
        *(int *)(param_3 + 0x24) = *(int *)(param_3 + 0x24) + _DAT_006e4a1c;
      }
    }
    else {
      *(int *)(param_3 + 0x24) = *(int *)(param_3 + 0x24) + _DAT_006e4a18;
    }
    iVar4 = *(int *)(local_8 + 0x118);
    if ((*(short *)(iVar4 + 0x4e) == 0) && (*(short *)(iVar4 + 0x50) == 0)) {
      if (*(short *)(iVar4 + 0x8a) == 0) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x28) + 1;
      sVar3 = FUN_00432249();
      iVar4 = (int)sVar3;
      if (0 < iVar4) {
        cVar2 = FUN_00422665(local_8 + 0xf4);
        if (cVar2 == '\0') {
          iVar5 = FUN_004670a4(*(undefined2 *)(local_8 + 0x84));
          if (iVar5 != 0) {
            cVar2 = FUN_00468851();
            if (cVar2 == '\0') {
              *(int *)(param_3 + 0x1c) = *(int *)(param_3 + 0x1c) + iVar4;
            }
            else {
              *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + iVar4;
            }
          }
        }
      }
    }
  }
  return;
}

