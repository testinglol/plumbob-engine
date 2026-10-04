
int __fastcall FUN_004286d1(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined **local_118 [3];
  undefined1 local_10c [260];
  undefined4 local_8;
  
  local_8 = 0;
  iVar6 = *(int *)(*DAT_006e486c + 0x10);
  if (*(int *)(iVar6 + 0x10c) == 0) {
    cVar2 = FUN_004074f7();
    if (cVar2 == '\0') {
      cVar2 = FUN_00407525();
      if (cVar2 == '\0') {
        cVar2 = FUN_004074d9();
        if (cVar2 == '\0') {
          cVar2 = FUN_0040750e();
          if (cVar2 == '\0') {
            cVar2 = FUN_0042886f();
            if (cVar2 == '\0') goto LAB_004287b3;
          }
        }
      }
    }
    puVar3 = (undefined4 *)FUN_004102ab(0);
    if (puVar3 == (undefined4 *)0x0) goto LAB_004287b3;
    local_8 = *(undefined4 *)(iVar6 + 0x118);
    uVar4 = FUN_004e988f(*puVar3);
    iVar6 = FUN_004e9744(uVar4);
    piVar5 = *(int **)(param_1 + 0x154);
    if (piVar5 != *(int **)(param_1 + 0x158)) {
      do {
        if (*(int *)(*piVar5 + 0x10c) == (int)*(short *)(iVar6 + 0x606)) {
          iVar6 = *piVar5;
          goto LAB_004287ac;
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 != *(int **)(param_1 + 0x158));
    }
    iVar6 = 0;
  }
  else {
    local_8 = FUN_0046d9e5();
  }
LAB_004287ac:
  *(uint *)(iVar6 + 0x138) = *(uint *)(iVar6 + 0x138) & 0xfffffff7;
LAB_004287b3:
  *(undefined4 *)(iVar6 + 0x118) = local_8;
  FUN_0046f824(local_10c,0,0x104);
  local_118[0] = &PTR_FUN_006664e8;
  FUN_00425691(*(undefined4 *)(param_1 + 0x164),local_118);
  iVar6 = FUN_00416153(local_118);
  do {
    piVar5 = *(int **)(param_1 + 0x148);
    while( true ) {
      if (piVar5 == *(int **)(param_1 + 0x14c)) {
        if (iVar6 == 0) {
          FUN_00425316(DAT_006e486c[0x11]);
        }
        return iVar6;
      }
      iVar1 = *piVar5;
      if ((((iVar1 != 0) && (((byte)*(undefined4 *)(*(int *)(iVar1 + 8) + 0xb4) & 0xc) == 4)) &&
          (*(short *)(iVar1 + 0xee) == 0)) && (*(short *)(iVar1 + 0xfa) == 0)) break;
      piVar5 = piVar5 + 1;
    }
    FUN_00427017(*piVar5);
  } while( true );
}

