
int __fastcall FUN_00523265(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x114) + 0xf8);
  if (-2 < iVar1) {
    iVar3 = FUN_005231fb();
    iVar7 = 0;
    if (iVar3 != 0) {
      iVar3 = FUN_004102e1();
      local_c = -1;
      local_8 = 0;
      if (iVar3 < 1) {
        return 0;
      }
      do {
        if (iVar1 <= local_c) {
          return iVar7;
        }
        puVar4 = (undefined4 *)FUN_004102ab(local_8);
        iVar5 = FUN_0043acf5(*puVar4);
        if ((iVar5 != 0) && (cVar2 = FUN_00523046(puVar4), cVar2 != '\0')) {
          local_c = local_c + 1;
          psVar6 = (short *)FUN_00425769(*puVar4);
          iVar7 = (int)*psVar6;
        }
        local_8 = local_8 + 1;
      } while (local_8 < iVar3);
      return iVar7;
    }
  }
  return 0;
}

