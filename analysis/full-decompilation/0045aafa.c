
/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_0045aafa(int param_1,int param_2,short *param_3)

{
  short sVar1;
  char cVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [3];
  
  sVar1 = *param_3;
  if (sVar1 == 0) {
    FUN_0058a039((int)*(short *)(param_2 + 4));
    return 1;
  }
  if (sVar1 == 1) {
    if (*(int *)(param_2 + 8) != 0) goto LAB_0045acec;
    if (*(short *)(param_1 + 0x58c) != 0) {
      return 0;
    }
    FUN_0042ede2(*(undefined4 *)(param_1 + 0xae0),*(undefined4 *)(param_1 + 0xae4));
    local_24 = *(undefined4 *)(param_1 + 0xf4);
    local_20 = *(undefined4 *)(param_1 + 0xf8);
    local_1c = *(int *)(param_1 + 0xf4);
    local_18 = *(int *)(param_1 + 0xf8);
    FUN_0047bd91(&local_18,&local_1c,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
    FUN_00422055(1,1);
    local_10[0] = local_10[0] + local_18;
    local_14 = local_14 + local_1c;
    FUN_0047bd91(local_10,&local_14,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
    FUN_0045f7c5(&local_24);
    FUN_0045f7c5(&local_24);
    FUN_0045f7c5(&local_14);
    *(undefined2 *)(param_1 + 0x5c) = 0;
  }
  else {
    if ((sVar1 < 2) || (3 < sVar1)) {
      local_10[1] = 0x27;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10 + 1,&DAT_00698f30);
    }
    if (*(int *)(param_2 + 8) != 0) goto LAB_0045acec;
    if (*(short *)(param_1 + 0x58c) != 0) {
      return 0;
    }
    iVar3 = FUN_00407498((int)*(short *)(param_2 + 4));
    if (iVar3 == 0) {
      local_10[2] = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10 + 2,&DAT_00698f30);
    }
    FUN_0042ede2(*(undefined4 *)(param_1 + 0xae0),*(undefined4 *)(param_1 + 0xae4));
    local_1c = *(int *)(param_1 + 0xf4);
    local_18 = *(int *)(param_1 + 0xf8);
    local_14 = *(int *)(iVar3 + 0xf4);
    local_10[0] = *(int *)(iVar3 + 0xf8);
    if (*param_3 == 3) {
      local_10[0] = local_10[0] + (*(int *)(iVar3 + 0xf8) - local_18) * -2;
      local_14 = local_14 + (*(int *)(iVar3 + 0xf4) - local_1c) * -2;
    }
    FUN_0045f7c5(&local_1c);
    FUN_0045f7c5(&local_1c);
    FUN_0045f7c5(&local_14);
  }
  FUN_00589c89();
  *(undefined4 *)(param_2 + 8) = 1;
LAB_0045acec:
  iVar3 = FUN_00589d4b();
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  if ((iVar3 != 2) && (cVar2 = FUN_00589e31(), cVar2 == '\0')) {
    iVar3 = 2;
  }
  return iVar3;
}

