
void __thiscall FUN_0046d0cf(DWORD param_1,int param_2,int param_3)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  undefined2 uVar5;
  undefined2 extraout_var;
  DWORD DVar6;
  int iVar7;
  undefined4 uVar8;
  DWORD local_c;
  DWORD local_8;
  
  iVar3 = param_2;
  local_c = param_1;
  local_8 = param_1;
  if (param_3 < 0x12) {
    FUN_00464973(param_1 + 0x10,0x10);
    local_8 = (DWORD)*(short *)(param_1 + 0x30);
    FUN_00464a5e(&local_8,1);
    *(undefined2 *)(param_1 + 0x30) = (undefined2)local_8;
  }
  else {
    uVar5 = *(undefined2 *)(param_1 + 0x42);
    if (param_3 < 0x41) {
      uVar8 = 0x20;
    }
    else {
      uVar8 = 0x40;
    }
    FUN_00464973(param_1 + 0x10,uVar8);
    *(undefined2 *)(param_1 + 0x42) = uVar5;
    *(short *)(param_1 + 0x2e) = (short)*(char *)(DAT_006e486c + 100);
  }
  FUN_00464a5e(param_1 + 0x98,1);
  local_c = CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x1a8));
  FUN_00464973(&local_c,1);
  *(int *)(param_1 + 0x1a8) = (int)(short)local_c;
  if (1 < param_3) {
    FUN_00464a5e(param_1 + 0x90,1);
  }
  if (param_3 < 6) {
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 2000;
    *(undefined2 *)(param_1 + 0x10) = 1;
    *(undefined2 *)(param_1 + 0x12) = 0xf;
    *(undefined2 *)(param_1 + 0x1e) = 6;
    *(undefined2 *)(param_1 + 0x20) = 0x7cd;
  }
  if (0xd < param_3) {
    FUN_00464a5e((DWORD *)(param_1 + 0xac),1);
    local_8 = FUN_0046f546();
    FUN_00464a5e(&local_8,1);
    cVar4 = FUN_004074bc();
    DVar6 = local_8;
    if (cVar4 != '\x01') {
      DVar6 = timeGetTime();
      *(DWORD *)(param_1 + 0xac) = DVar6;
      DVar6 = timeGetTime();
    }
    FUN_0046f54c(DVar6);
  }
  piVar1 = (int *)(param_1 + 0x94);
  if (param_3 < 0xf) {
    *piVar1 = 0;
  }
  else {
    FUN_00464a5e(piVar1,1);
  }
  iVar7 = *piVar1;
  *piVar1 = 0;
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + iVar7;
  if (param_3 < 0x11) {
    *(undefined2 *)(param_1 + 0x10) = 5;
    *(undefined2 *)(param_1 + 0x1a) = 0x37;
    uVar5 = FUN_0046d641();
    *(undefined2 *)(param_1 + 0x18) = uVar5;
    FUN_0046d9f8(*(undefined4 *)(param_1 + 0x90));
  }
  if (param_3 < 0x15) {
    sVar2 = *(short *)(param_1 + 0x30);
    *(undefined2 *)(param_1 + 0x34) = 0xffff;
    if (sVar2 == 0) {
      *(undefined2 *)(param_1 + 0x32) = 1;
LAB_0046d26f:
      uVar5 = FUN_004425e2();
    }
    else {
      *(undefined2 *)(param_1 + 0x32) = 0;
      if (sVar2 == 1) {
        uVar5 = FUN_0046d37c();
      }
      else {
        if (sVar2 == 2) goto LAB_0046d26f;
        if (sVar2 == 3) {
          uVar5 = FUN_0046d380();
        }
        else if (sVar2 == 4) {
          uVar5 = FUN_0046d386();
        }
        else {
          uVar5 = (undefined2)param_2;
        }
      }
    }
    *(undefined2 *)(param_1 + 0x30) = uVar5;
  }
  if (param_3 < 0x25) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0x1194;
  }
  else {
    FUN_00464a4e(param_1 + 0x9c,1);
    FUN_00464a4e(param_1 + 0xa0,1);
    FUN_00464a4e(param_1 + 0xa4,1);
  }
  if (param_3 < 0x26) {
    if (*(int *)(param_2 + 0xc) != 0) {
      return;
    }
  }
  else {
    FUN_0046d38c(param_1 + 0x184,param_2);
    iVar7 = param_1 + 0xe4;
    param_2 = 5;
    do {
      FUN_0046d38c(iVar7,iVar3);
      iVar7 = iVar7 + 0x20;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (0x33 < param_3) goto LAB_0046d342;
  }
  FUN_0046da96();
LAB_0046d342:
  if (*(int *)(iVar3 + 0xc) == 0) {
    FUN_0046d7b3((int)*(short *)(param_1 + 0x30));
    uVar5 = FUN_0047365d((int)*(short *)(param_1 + 0x20),(int)*(short *)(param_1 + 0x1e));
    *(undefined2 *)(param_1 + 0x4a) = uVar5;
    *(ushort *)(param_1 + 0x4c) = (ushort)DAT_006c2970;
  }
  return;
}

