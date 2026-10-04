
int __thiscall FUN_00469a9d(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = param_2;
  piVar2 = (int *)FUN_00469872(param_2);
  iVar5 = 0;
  if (piVar2 != (int *)0x0) {
    if (piVar2[2] == -1) {
      piVar2[2] = 0;
      piVar2[3] = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30) >> 2;
      if (iVar1 == 0) {
        for (piVar3 = *(int **)(param_1 + 0x24); piVar3 != *(int **)(param_1 + 0x28);
            piVar3 = piVar3 + 1) {
          if (*piVar3 != -1) {
            FUN_0040555d(piVar3);
            piVar2[2] = piVar2[2] + 1;
          }
        }
      }
      else if (iVar1 != 1) {
        FUN_00469ef7(iVar1);
        piVar2 = (int *)FUN_00469872(iVar1);
        for (piVar3 = *(int **)(param_1 + 0x18); piVar3 != *(int **)(param_1 + 0x1c);
            piVar3 = piVar3 + 1) {
          if (iVar1 == *piVar3) {
            piVar2[2] = piVar2[2] + 1;
            param_2 = 1;
            FUN_0040555d(&param_2);
            break;
          }
        }
        piVar3 = *(int **)(param_1 + 0x24);
LAB_00469b42:
        if (piVar3 != *(int **)(param_1 + 0x28)) {
          if (iVar1 != *piVar3) goto code_r0x00469b4a;
          for (piVar3 = *(int **)(param_1 + 0x18); piVar3 != *(int **)(param_1 + 0x1c);
              piVar3 = piVar3 + 1) {
            if (*piVar3 != -1) {
              piVar4 = (int *)FUN_00469872(*piVar3);
              if (((piVar4 != (int *)0x0) && (piVar4[1] == piVar2[1])) && (*piVar4 == *piVar2)) {
                piVar2[2] = piVar2[2] + 1;
                FUN_0040555d(piVar3);
              }
            }
          }
        }
      }
    }
    iVar5 = piVar2[2];
  }
  return iVar5;
code_r0x00469b4a:
  piVar3 = piVar3 + 1;
  goto LAB_00469b42;
}

