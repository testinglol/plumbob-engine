
/* WARNING: Removing unreachable block (ram,0x006335bb) */
/* WARNING: Removing unreachable block (ram,0x006335c3) */

int * __thiscall FUN_00633585(int *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 local_14 [16];
  
  iVar2 = FUN_006327fb(0);
  if (iVar2 != 0) {
    uVar3 = FUN_0063411f(local_14);
    iVar2 = FUN_0063903a(local_14,0,uVar3);
    if ((iVar2 == -1) && (piVar4 = (int *)FUN_0063d796(), *piVar4 == 0x22)) {
      *param_2 = -1;
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 2;
    }
    else {
      *param_2 = iVar2;
    }
    FUN_00632716();
  }
  return param_1;
}

