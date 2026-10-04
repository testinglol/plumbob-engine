
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0063332a(undefined8 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *extraout_ECX;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char local_2c;
  char local_2b [7];
  undefined4 uStack_24;
  char *pcStack_20;
  char *pcStack_1c;
  undefined8 local_18;
  
  FUN_00636080();
  pcVar4 = &local_2c;
  iVar2 = extraout_ECX[1];
  extraout_ECX[1] = 0;
  uVar5 = *(uint *)(*(int *)(*extraout_ECX + 4) + 0x28 + (int)extraout_ECX);
  uVar6 = (-(uint)(iVar2 != 0) & 0xfffffff7) + 0xf;
  if (uVar5 < uVar6) {
    uVar6 = uVar5;
  }
  local_18 = CONCAT44(0x633368,(undefined4)local_18);
  iVar2 = FUN_006322ac();
  if (iVar2 != 0) {
    uVar5 = (uint)((*(byte *)(*(int *)(*extraout_ECX + 4) + 0x25 + (int)extraout_ECX) & 4) != 0);
    if ((*(byte *)(*(int *)(*extraout_ECX + 4) + 0x25 + (int)extraout_ECX) & 1) != 0) {
      (&stack0xfffffff8)[uVar5] = 0x23;
      uVar5 = uVar5 + 1;
    }
    (&stack0xfffffff8)[uVar5] = 0;
    local_18 = CONCAT44(uVar6,&stack0xfffffff8);
    pcStack_20 = (char *)((int)&local_18 + 4);
    pcStack_1c = "%%%s.%.0ug";
    uStack_24 = 0x6333ab;
    iVar3 = FUN_00635858();
    iVar2 = *extraout_ECX;
    uVar5 = *(uint *)(*(int *)(iVar2 + 4) + 0x24 + (int)extraout_ECX) & _DAT_0068904c;
    if (uVar5 == 0x1000) {
      *(undefined1 *)((int)&local_18 + iVar3 + 3) = 0x66;
    }
    else {
      if (uVar5 == 0x800) {
        *(undefined1 *)((int)&local_18 + iVar3 + 3) = 0x65;
      }
      if ((*(byte *)(*(int *)(iVar2 + 4) + 0x25 + (int)extraout_ECX) & 2) != 0) {
        local_18 = CONCAT44((int)*(char *)((int)&local_18 + iVar3 + 3),0x6333f3);
        uVar1 = FUN_00638af3();
        *(undefined1 *)((int)&local_18 + iVar3 + 3) = uVar1;
      }
    }
    pcStack_1c = (char *)((int)&local_18 + 4);
    local_18 = param_1;
    pcStack_20 = &local_2c;
    uStack_24 = 0x63340b;
    FUN_00635858();
    local_18._4_4_ = 0;
    if ((local_2c == '+') || (local_2c == '-')) {
      local_18._4_4_ = 1;
      pcVar4 = local_2b;
    }
    (&stack0xfffffff8)[local_18._4_4_] = 0;
    local_18 = CONCAT44(pcVar4,&stack0xfffffff8);
    pcStack_1c = (char *)0x63343c;
    FUN_00632520();
    local_18 = CONCAT44(0x633443,(undefined4)local_18);
    FUN_00632320();
  }
  return extraout_ECX;
}

