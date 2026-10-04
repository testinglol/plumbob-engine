
void __thiscall FUN_00427c21(int param_1,int param_2)

{
  short *psVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  int local_c;
  int local_8;
  
  local_c = 0;
  puVar7 = *(undefined4 **)(param_1 + 0x148);
  if (puVar7 != *(undefined4 **)(param_1 + 0x14c)) {
    do {
      psVar1 = (short *)*puVar7;
      if (psVar1 != (short *)0x0) {
        uVar3 = FUN_00401f73();
        cVar2 = FUN_00410285(uVar3);
        if ((cVar2 == '\0') && (psVar1[0x77] != 0)) {
          local_8 = 0;
          iVar4 = FUN_004102e1();
          if (0 < iVar4) {
            do {
              puVar5 = (undefined4 *)FUN_004102ab(local_8);
              psVar6 = (short *)FUN_00425769(*puVar5);
              if (((psVar6 != (short *)0x0) &&
                  (cVar2 = FUN_0042720f(psVar1 + 6,(int)*psVar1,psVar6 + 6,(int)*psVar6),
                  cVar2 != '\0')) && (psVar1[0x7b] < 2)) {
                local_c = local_c + 1;
                break;
              }
              local_8 = local_8 + 1;
              iVar4 = FUN_004102e1();
            } while (local_8 < iVar4);
          }
        }
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != *(undefined4 **)(param_1 + 0x14c));
  }
  *(undefined1 *)(param_2 + 0x124) = 0;
  *(int *)(param_2 + 0x120) = local_c;
  return;
}

