
void __fastcall FUN_0046dcc7(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int local_4;
  
  piVar1 = (int *)**(int **)(param_1 + 0x1a4);
  local_4 = param_1;
  if (piVar1 != *(int **)(param_1 + 0x1a4)) {
    do {
      *(short *)(piVar1 + 6) = *(short *)(piVar1 + 6) + 1;
      if (*(short *)(piVar1 + 6) < 100) {
        puVar2 = (undefined4 *)*piVar1;
      }
      else {
        puVar2 = (undefined4 *)*piVar1;
        FUN_0046ddb6(&local_4,piVar1);
      }
      piVar1 = puVar2;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x1a4));
  }
  return;
}

